use std::{vec, ptr::eq};
enum Lamp_pos
{
    stG = 0,
    enG,
    bridge
}

fn simulation( input : Vec<u64>) -> u64
{
    let mut cost : u64 = 0;
    let mut stG : Vec<u64> = Vec::new();
    let mut enG : Vec<u64> = Vec::new();
    let mut bridge: Vec<u64> = Vec::new();
    let mut lamp = Lamp_pos::stG;
    stG = input;
    
    
    loop
    {
        if bridge.len() + stG.len() == 0 {break};

        if matches!(lamp, Lamp_pos::stG){
            if stG.is_empty() {
                println!("error");
                return cost
            }
            if stG.len() == 1 {
                return cost + stG[0];
            }

            for _ in 0 ..= 1 {
                bridge.push(stG.pop().unwrap());
            }
            
            lamp = Lamp_pos::bridge;
            
            cost = cost + bridge.iter().max().unwrap();
            continue;
            
        }

        if matches!(lamp , Lamp_pos::bridge)
        {
            

            while bridge.is_empty() 
            {
                enG.push(bridge.pop().unwrap());
            }
            lamp = Lamp_pos::enG;
            break;
        }

        if matches!(lamp , Lamp_pos::enG) {
            if !stG.is_empty()
            {

            }
            break;
        }

    }

    return cost;
}
fn main() {
    
    println!("{}",simulation(vec![1,2]));
    println!("Hello, world!");

}
