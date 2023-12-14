use std::fs::File;
use std::io::Read;

pub fn read_file(filename: &str) -> String {
    let open_file_result = File::open(filename);
    let mut file = match open_file_result {
        Err(error) => panic!("Problem opening the file: {:?}:", error),
        Ok(open_file) => open_file,
    };
    let mut s = String::new();
    match file.read_to_string(&mut s) {
        Err(error) => panic!("Couldn't read {}: {}", filename, error),
        Ok(_) => (),
    }
    s
}

pub fn read_lines(filename: &str) -> Vec<String> {
    let file_content = read_file(filename);
    let parts = file_content.split("\n");
    let mut v: Vec<String> = Vec::with_capacity(200);
    for part in parts {
        if part.is_empty() {
            continue;
        }
        v.push(String::from(part));
    }
    v
}

pub fn get_nums(line: String) -> Vec<i64> {
    let parts = line.split_whitespace();
    let mut v: Vec<i64> = Vec::with_capacity(10);
    for part in parts {
        let parsed = match part.parse::<i64>() {
            Ok(x) => x,
            Err(_) => continue,
        };
        v.push(parsed);
    }
    v
}

pub fn get_lines_nums(filename: &str) -> Vec<Vec<i64>> {
    let str_lines = read_lines(filename);
    let mut v: Vec<Vec<i64>> = Vec::with_capacity(200);
    for line in str_lines {
        v.push(get_nums(line));
    }
    v
}
