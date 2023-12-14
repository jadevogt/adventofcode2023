use std::collections::{HashMap, HashSet};
use crate::ten::Direction::{East, North, South, West};

#[derive(Debug, PartialEq, Eq)]
pub enum Direction {
    North,
    South,
    East,
    West,
}

#[derive(Debug)]
pub enum Tile {
    Pipe(Vec<Direction>),
    Ground,
    Animal,
}

pub fn parse_tile(c: &char) -> Tile {
    match c {
        '|' => Tile::Pipe(vec![Direction::North, Direction::South]),
        '-' => Tile::Pipe(vec![Direction::East, Direction::West]),
        'L' => Tile::Pipe(vec![Direction::North, Direction::East]),
        'J' => Tile::Pipe(vec![Direction::North, Direction::West]),
        'F' => Tile::Pipe(vec![Direction::South, Direction::East]),
        '7' => Tile::Pipe(vec![Direction::South, Direction::West]),
        'S' => Tile::Animal,
        _ => Tile::Ground
    }
}

pub fn print_tile(t: &Tile) {
    match t {
        Tile::Pipe(x) => {
            if (x.contains(&Direction::North) && x.contains(&Direction::South)) {
                print!("┃"); // |
            }
            if (x.contains(&Direction::East) && x.contains(&Direction::West)) {
                print!("━"); // -
            }
            if (x.contains(&Direction::North) && x.contains(&Direction::East)) {
                print!("┗"); // L
            }
            if (x.contains(&Direction::North) && x.contains(&Direction::West)) {
                print!("┛"); // J
            }
            if (x.contains(&Direction::East) && x.contains(&Direction::South)) {
                print!("┏"); // F
            }
            if (x.contains(&Direction::West) && x.contains(&Direction::South)) {
                print!("┓"); // 7
            }
        },
        Tile::Animal => {
            print!("┛");
        },
        _ => {
            print!(" ")
        }
    }
}

pub fn pprint_tile(t: &Tile, ) {
    match t {
        Tile::Pipe(x) => {
            if (x.contains(&Direction::North) && x.contains(&Direction::South)) {
                print!("┃"); // |
            }
            if (x.contains(&Direction::East) && x.contains(&Direction::West)) {
                print!("━"); // -
            }
            if (x.contains(&Direction::North) && x.contains(&Direction::East)) {
                print!("┗"); // L
            }
            if (x.contains(&Direction::North) && x.contains(&Direction::West)) {
                print!("┛"); // J
            }
            if (x.contains(&Direction::East) && x.contains(&Direction::South)) {
                print!("┏"); // F
            }
            if (x.contains(&Direction::West) && x.contains(&Direction::South)) {
                print!("┓"); // 7
            }
        },
        Tile::Animal => {
            print!("┛");
        },
        _ => {
            print!(" ")
        }
    }
}

pub fn expand_tile(t: &Tile, coords_in: (usize, usize), ex_map: &mut Vec<Vec<char>>, pipes_map: &HashMap<(usize, usize), &Tile>) {
    let center: (usize, usize) = ((coords_in.0 * 3) + 1, (coords_in.1 * 3)+1);
    match t {
        Tile::Ground => {
            ex_map[center.1][center.0] = 'X';
        },
        Tile::Animal => {
            ex_map[center.1 - 1][center.0] = 'W';
            ex_map[center.1][center.0] = 'W';
            ex_map[center.1][center.0 - 1] = 'W';
        },
        Tile::Pipe(x) => {
            if !pipes_map.contains_key(&coords_in) {
                ex_map[center.1][center.0] = 'X';
                return;
            }
            ex_map[center.1][center.0] = 'W';
            if x.contains(&North) {
                ex_map[center.1 - 1][center.0] = 'W';
            }
            if x.contains(&South) {
                ex_map[center.1 + 1][center.0] = 'W';
            }
            if x.contains(&East) {
                ex_map[center.1][center.0 + 1] = 'W';
            }
            if x.contains(&West) {
                ex_map[center.1][center.0 - 1] = 'W';
            }
        }
    }
}

pub fn flood_fill(in_coords: (usize, usize), map: &mut Vec<Vec<char>>) {
    let mut s: Vec<(usize, usize)> = Vec::new();
    s.push(in_coords);

    while(!s.is_empty()) {
        let c = s.pop().expect("Whoops");
        let x = c.0;
        let y = c.1;
        map[y][x] = 'O';
        if (x > 0 && (map[y][x-1] == ' ' || map[y][x-1] == 'X')) {
            s.push((x-1, y));
        }
        if (y > 0 && (map[y-1][x] == ' ' || map[y-1][x] == 'X')) {
            s.push((x, y-1));
        }
        if (x < map[y].len() - 1 && (map[y][x+1] == ' ' || map[y][x+1] == 'X')) {
            s.push((x+1, y));
        }
        if (y < map.len() - 1 && (map[y+1][x] == ' ' || map[y+1][x] == 'X' )) {
            s.push((x, y+1));
        }
    }

}


pub fn move_direction(coords_in: (usize, usize), dir: &Direction) -> (usize, usize) {
    let n = match dir {
        North => (coords_in.0, coords_in.1 - 1),
        South => (coords_in.0, coords_in.1 + 1),
        East => (coords_in.0 + 1, coords_in.1),
        West => (coords_in.0 - 1, coords_in.1),
    };
    n
}

pub fn reverse_direction(dir: &Direction) -> Direction {
    match dir {
        North => South,
        South =>North,
        East => West,
        West => East,
    }
}

pub fn check_direction(map: &Vec<Vec<Tile>>, coords_in: (usize, usize), dir: Direction) -> bool {
    let new = move_direction(coords_in, &dir);
    let n = &map[new.1][new.0];
    match n {
        Tile::Pipe(x) => {
            x.contains(&reverse_direction(&dir))
        }
        _ => false
    }
}

pub fn move_tile(map: &Vec<Vec<Tile>>, coords_in: (usize, usize), dir_from: Direction) -> (Direction, (usize, usize)) {
    let x = &map[coords_in.1][coords_in.0];
    match x {
        Tile::Pipe(x) => {
            let new_direction = match x.iter().find(|x| **x != dir_from) {
                Some(x) => x,
                _ => panic!("aaaaa")
            };
            let new_coords = move_direction(coords_in, new_direction);
            return (reverse_direction(&new_direction), new_coords)
        }
        _ => panic!("Oh no")
    }
    panic!("Oh no")
}
