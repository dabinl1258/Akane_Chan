use std::io;
fn ReadV() -> Vec<u64>
{
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);
    buffer = buffer.split(" ").collect();
    
    let nums : Vec<u32> = buffer.chars()
    .filter_map(|c | c.to_digit(10)).collect();

    nums.into_iter().map(|x|x as u64 ).collect()
    

    
}

fn N2F( mut num : u64) -> Vec<u64>
{
    let mut factor : Vec<u64> = vec![0,0,0,0];
    while num > 1  
    {
        if num % 2 == 0 {
            num /= 2;
            factor[0] += 1;
        }

        if num % 3 == 0 {
            num /= 3;
            factor[1] += 1;
        }

        if num % 5 == 0 {
            num /= 5;
            factor[2] += 1;
        }

        if num % 7 == 0 
        {
            num /= 7;
            factor[3] += 1;
        }
    }
    return factor        
}
fn GreaterThenED(st_num : &Vec<u64> , ed_num : &Vec<u64>) -> bool {
    for i in 0 .. 4 as usize {
        if st_num[i] >  ed_num[i]{
            return true;
        }
    }
    false 
}
fn IsFactorEven(st_num : &Vec<u64> , ed_num : &Vec<u64>) -> bool
{
    for i in 0 .. 4 as usize {
        let nf = st_num[i] + ed_num[i];
        if nf % 2 == 1 {
            return false;
        }
    }
    
    true
}
fn SameFactor(st_num : &Vec<u64> , ed_num : &Vec<u64>) -> bool {
    for i in 0 .. 4 as usize {
        if st_num[i] != ed_num[i]{
            return false;
        }
    }
    true
}
fn main() {
    let input : Vec<u64> = ReadV();
    let mut st_num : Vec<u64> = vec![0,0,0,0];
    let mut ed_num : Vec<u64> = vec![0,0,0,0];
    let mut split_index = 0 as usize;
    
    st_num = N2F(*input.first().unwrap());


    
    
    for i in 1 .. input.len()
    {
        let mut num = input[i];
        let factor = N2F(num);
        for i in 0 .. 4 as usize{
            ed_num[i] += factor[i];
        }
    }
    

    for i in 1 .. input.len()
    {
        if SameFactor(&st_num, &ed_num){
            println!("YES");
            return ;
        }
        if GreaterThenED(&st_num, &ed_num){
            println!("NO");
            return ;
        }
        let mut num = input[i];
        let factor = N2F(num);
        for i in 0 .. 4 as usize{
            ed_num[i] -= factor[i];
            st_num[i] += factor[i];
        }
    }

    
    println!("NO");


    
}
