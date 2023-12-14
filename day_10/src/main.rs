use std::collections::{HashMap, HashSet};
use crate::advent::read_lines;
use crate::ten::{Tile, Direction, parse_tile, check_direction, move_direction, move_tile, print_tile, expand_tile, flood_fill};
use crate::ten::Direction::{North, South, East, West};

pub mod advent;
pub mod ten;

fn main() {
    let str_map = read_lines("inputs/input.txt");
    let mut map: Vec<Vec<Tile>> = Vec::new();
    let mut coords: (usize, usize) = (0, 0);
    for (index_line, line) in str_map.iter().enumerate() {
        let str_row: Vec<char> = line.chars().collect();
        let mut row: Vec<Tile> = Vec::new();
        for (index_c, c) in str_row.iter().enumerate() {
            row.push(parse_tile(c));
            if *c == 'S' {
                coords = (index_c, index_line);
                println!(" {}, {} ", index_c, index_line);
            }
        }
        map.push(row);
    }

    for row in &map {
        for tile in row {
            match tile {
                Tile::Animal => print!("A "),
                Tile::Pipe(x) => print!("Pipe {:?} ", x),
                Tile::Ground => print!("  "),
            }
        }
        print!("\n");
    }
    let mut pipes: Vec<(usize, usize)> = Vec::new();
    let mut pipes_map: HashMap<(usize, usize), &Tile> = HashMap::new();
    println!("North: {}", check_direction(&map, coords, North));
    println!("South: {}", check_direction(&map, coords, South));
    println!("East: {}", check_direction(&map, coords, East));
    println!("West: {}", check_direction(&map, coords, West));
    if check_direction(&map, coords, North) {
        let initial_coords = coords;
        pipes.push(initial_coords);
        pipes_map.insert(initial_coords, &map[initial_coords.1][initial_coords.0]);
        let mut current_coords = move_direction(initial_coords, &North);
        let mut step_count = 1;
        let mut current_direction = South;
        while (current_coords != initial_coords) {
            pipes.push(current_coords);
            pipes_map.insert(current_coords, &map[current_coords.1][current_coords.0]);
            let x = move_tile(&map, current_coords, current_direction);
            current_direction = x.0;
            current_coords = x.1;
            step_count +=1;
        }
        println!("{}", step_count / 2);
    }
    for (row_idx, row) in map.iter().enumerate() {
        for (col_idx, tile) in row.iter().enumerate() {
            match pipes_map.get(&(col_idx, row_idx)) {
                Some(x) => {print_tile(tile)},
                _ => {print!(" ")}
            }
        }
        print!("\n");
    }
    let mut ex_map: Vec<Vec<char>> = Vec::new();
    for x in 0..(map.len() * 3) {
        ex_map.push(Vec::new());
        for y in 0..(map[0].len() * 3) {
            ex_map[x].push(' ');
        }
    }
    for (row_idx, row) in map.iter().enumerate() {
        for (col_idx, tile) in row.iter().enumerate() {
            expand_tile(tile, (col_idx, row_idx), &mut ex_map, &pipes_map);
        }
    }
    let mut old: HashSet<char> = HashSet::new();
    old.insert(' ');
    old.insert('X');
    for row in &ex_map {
        for col in row {
            print!("{}", col);
        }
        print!("\n");
    }
    flood_fill((0,0), &mut ex_map);

    let mut t = 0;
    for row in ex_map {
        for col in row {
            print!("{}", col);
            if col == 'X' {
                t += 1;
            }
        }
        print!("\n");
    }
    print!("{} spaces", t);
}

pub fn part_one() {
    let str_map = read_lines("inputs/input.txt");
    let mut map: Vec<Vec<Tile>> = Vec::new();
    let mut coords: (usize, usize) = (0, 0);
    for (index_line, line) in str_map.iter().enumerate() {
        let str_row: Vec<char> = line.chars().collect();
        let mut row: Vec<Tile> = Vec::new();
        for (index_c, c) in str_row.iter().enumerate() {
            row.push(parse_tile(c));
            if *c == 'S' {
                coords = (index_c, index_line);
                println!(" {}, {} ", index_c, index_line);
            }
        }
        map.push(row);
    }

    for row in &map {
        for tile in row {
            match tile {
                Tile::Animal => print!("A "),
                Tile::Pipe(x) => print!("Pipe {:?} ", x),
                Tile::Ground => print!("  "),
            }
        }
        print!("\n");
    }
    println!("North: {}", check_direction(&map, coords, North));
    println!("South: {}", check_direction(&map, coords, South));
    println!("East: {}", check_direction(&map, coords, East));
    println!("West: {}", check_direction(&map, coords, West));
    if check_direction(&map, coords, North) {
        let initial_coords = coords;
        let mut current_coords = move_direction(initial_coords, &North);
        let mut step_count = 1;
        let mut current_direction = South;
        while (current_coords != initial_coords) {
            let x = move_tile(&map, current_coords, current_direction);
            current_direction = x.0;
            current_coords = x.1;
            step_count +=1;
        }
        println!("{}", step_count / 2);
    }
}
