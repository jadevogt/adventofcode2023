pub fn continue_sequence(nums: &Vec<i64>) -> Vec<i64> {
    let mut v: Vec<i64> = Vec::new();
    for (index, num) in nums.iter().enumerate() {
        if index >= nums.len() - 1 {
            break;
        }
        v.push(nums[index + 1] - num);
    }
    v
}

pub fn complete_sequences(nums: &Vec<i64>) -> Vec<Vec<i64>> {
    let mut v: Vec<Vec<i64>> = Vec::new();
    v.push(nums.clone());
    while !(v[v.len() - 1].iter().all(|&x| x == 0)) {
        v.push(continue_sequence(&v[v.len() - 1]));
    }
    v
}

pub fn extrapolate(seqs: &Vec<Vec<i64>>) -> i64 {
    let mut result: i64 = 0;
    for (index, n) in seqs.iter().rev().enumerate() {
        if index == 0 {
            result = n[n.len() - 1];
            continue;
        }
        result += n[n.len() - 1];
    }
    result
}

pub fn extrapolate_backwards(seqs: &Vec<Vec<i64>>) -> i64 {
    let mut result: i64 = 0;
    for (index, n) in seqs.iter().rev().enumerate() {
        if (seqs.len() as i64 - 2 - index as i64) < 0 {
            continue;
        }
        let next_seq = &seqs[seqs.len() - 2 - index];
        result = -1 * (result - next_seq[0])
    }
    result
}

pub fn extrapolate_backwards_old(seqs: &Vec<Vec<i64>>) -> i64 {
    let mut result: i64 = 0;
    for (index, n) in seqs.iter().enumerate() {
        if index == 0 {
            result = n[0];
            continue;
        }
        result = n[0] - result;
    }
    result
}