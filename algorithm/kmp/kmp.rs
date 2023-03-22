use std::io;
use std::string;
use std::str::FromStr;
fn ReadLine() -> String {
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer);
    buffer = buffer.trim().to_string();
    buffer
}
fn KMPARR( _str : String ) -> Vec<usize>{
    let mut arr = vec![0; _str.len()];
    for i in 1 ..= _str.len(){
        let k = i / 2;
        let mut mat = 0;
        
        for j in 0 .. k {
            let prefix = &_str[0 .. k -j];
            let suffix = &_str[(i%2)+k + j .. i];
            if prefix.eq(suffix) {
                mat = k - j;
                break;
            }
        }
        arr[i-1] = mat;
        
    }
    arr
}

fn main() {
    let mut target = ReadLine();
    let mut matchStr = ReadLine();


    let arr = KMPARR(matchStr.clone());
    let mut idx = 0; 
    let mut j = 0;
    while idx < target.len(){
        println!("idx {} j {j} , arr[j]{} ", idx, arr[j]);
        if target.as_bytes()[idx] == matchStr.as_bytes()[j]{
            if j >= matchStr.len() -1{
                println!("match {} .. {}", idx-j , idx );
                j = arr[j];

            }
            else
            {
                j = j + 1;
            }
 
            idx = idx + 1;
       }
        
        else{
            if j > 1 {
                j = arr[j-1];
                println!("return");
            }
            else {
                idx = idx + 1;
            }
        }
    }

}
