use crate::advent::read_lines;
use itertools::Itertools;
use regex::Regex;

pub mod advent;

fn main() {
    part_one();
}

pub fn build_regex_str(runs: &Vec<i32>) -> String {
    let regex_sep = String::from(r#"\.{1,}"#);
    let mut regex_str = String::new();
    for run in runs {
        regex_str.push_str(&regex_sep);
        regex_str.push_str("#{");
        regex_str.push_str(&run.to_string());
        regex_str.push_str("}");
    }
    regex_str
}

pub fn part_one() {
    let lines = read_lines("inputs/test.txt");
    let mut symbols: Vec<Vec<char>> = Vec::new();
    let mut runs: Vec<Vec<i32>> = Vec::new();
    for line in lines {
        for (idx, sp) in line.split_whitespace().enumerate() {
            if idx == 0 {
                symbols.push(sp.chars().collect());
            } else if idx == 1 {
                let mut n: Vec<i32> = Vec::new();
                for num in sp.split(',') {
                    let x = String::from(num).parse().unwrap();
                    n.push(x);
                }
                runs.push(n);
            }
        }
    }
    let mut total = 0;
    for (idx, s) in symbols.iter().enumerate() {
        let max_sum = runs[idx].iter().sum();
        let regex_str = build_regex_str(&runs[idx]);
        let re = Regex::new(&regex_str).unwrap();
        let x = s.iter().map(|i| match i {
            '#' => vec!['#'].into_iter(),
            '.' => vec!['.'].into_iter(),
            '?' => vec!['.', '#'].into_iter(),
            _ => panic!("ERROR"),
        });
        let perms = x
            .into_iter()
            .multi_cartesian_product()
            .filter(|n| n.iter().filter(|&c| *c == '#').count() as i32 == max_sum)
            .filter(|p| {
                let mut s: String = String::from(".");
                let q: String = p.into_iter().collect();
                s.push_str(&q);
                return re.is_match(&s);
            });
        for _ in perms {
            total += 1;
        }
    }
    println!("Total for part 1 is {}", total);
}
