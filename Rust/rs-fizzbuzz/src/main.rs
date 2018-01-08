fn main() {
    let fizz_buzz = fizz_buzz(100);

    print!("{}", fizz_buzz);
}

fn fizz_buzz(count: u16) -> String {
    let mut fizz_buzz = String::default();    
    let mut current = 1;

    while current < count {
        if current % 15 == 0 {
            fizz_buzz.push_str("FizzBuzz\n");
        } else if current % 5 == 0 {
            fizz_buzz.push_str("Buzz\n");
        } else if current % 3 == 0 {
            fizz_buzz.push_str("Fizz\n");
        } else {
            fizz_buzz = format!("{}{}\n", fizz_buzz, current);
        }

        current += 1;
    }

    return fizz_buzz;
}
