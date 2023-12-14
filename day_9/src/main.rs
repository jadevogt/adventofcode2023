use crate::nine::{complete_sequences, extrapolate, extrapolate_backwards};

pub mod advent;
mod nine;

fn main() {
    let lines_nums = advent::get_lines_nums("inputs/input.txt");
    let mut total: i64 = 0;
    let mut other_total: i64 = 0;
    for (i, line) in lines_nums.iter().enumerate() {
        //print!("{}: ", i);
        let x = complete_sequences(line);
        let extrapolated =  extrapolate(&x);
        let bextrapolated =  extrapolate_backwards(&x);
        for seq in x {
            for num in seq {
                print!(" {} ", num);
            }
            print!("\n");
        }
        total += extrapolated;
        other_total += bextrapolated;
    }
    println!("Total is {}", total);
    println!("Total (part 2) is {}", other_total);
}


