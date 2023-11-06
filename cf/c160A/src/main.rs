use std::cmp::PartialEq;
use std::io;
use std::ops::{Add, Sub};
use std::result::Result::Ok;
use std::str::FromStr;

fn StrVecToU32Vec(v: Vec<&str>) -> Vec<u32> {
    v.iter().map(|x| StrToU32(x)).collect()
}
fn StrToVec(s: &str) -> Vec<&str> {
    s.split_whitespace().collect()
}
fn StrToU32(s: &str) -> u32 {
    match s.parse::<u32>() {
        Ok(k) => k,
        other => 0,
    }
}
fn read_number<T: FromStr>() -> T {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);
    buffer
        .split_whitespace()
        .next()
        .unwrap()
        .parse::<T>()
        .ok()
        .unwrap()
}
fn read_numbers<T: FromStr>() -> Vec<T> {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);
    buffer
        .split_whitespace()
        .map(|x| x.parse::<T>().ok().unwrap())
        .collect()
}
struct Wallet {
    money: u64,
    coins: u64,
}
impl Clone for Wallet {
    fn clone(&self) -> Self {
        Self {
            money: self.money,
            coins: self.coins,
        }
    }
}
impl PartialEq for Wallet {
    fn eq(&self, other: &Wallet) -> bool {
        self.money == other.money
    }
}
impl PartialOrd for Wallet {
    fn partial_cmp(&self, other: &Wallet) -> Option<std::cmp::Ordering> {
        self.money.partial_cmp(&other.money)
    }
}
impl Eq for Wallet {}
impl Ord for Wallet {
    fn cmp(&self, other: &Wallet) -> std::cmp::Ordering {
        let x = self.money.cmp(&other.money);
        x
    }
}
impl Wallet {
    fn new() -> Self {
        Wallet { money: 0, coins: 0 }
    }
}

fn logic(nums: Vec<i64>) {
    let mut coins = nums.clone();
    coins.sort();
    let mut accs = Vec::<i64>::new();
    let mut acc: i64 = 0;
    accs.push(0);
    for coin in coins.iter() {
        acc += coin;
        accs.push(acc.clone());
    }
    let mut ret = 0;
    for i in 1..accs.len() {
        let younger = accs[coins.len() - i];
        let older = acc - younger;
        if (older - younger) > 0 {
            ret = i;
            break;
        }
    }
    println!("{}", ret);
}
fn main() -> io::Result<()> {
    let k = read_number::<i64>();
    let nums = read_numbers::<i64>();
    logic(nums);
    Ok(())
}
