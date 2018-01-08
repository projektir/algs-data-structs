use std::borrow::Cow;

fn main() {
    print!("{}", fizz_buzz(100, &fizz_buzz_inner));
}

fn fizz_buzz(count: u16, f: &Fn(u16) -> Cow<'static, str>) -> String {
    let mut fizz_buzz = String::default();
    let mut current = 1u16;

    while current < count {
        fizz_buzz = format!("{}{}\n", fizz_buzz, f(current));

        current += 1;
    }

    return fizz_buzz;
}

fn fizz_buzz_inner(value: u16) -> Cow<'static, str> {
    if value % 15 == 0 {
        return Cow::from("FizzBuzz");
    } else if value % 5 == 0 {
        return Cow::from("Buzz");
    } else if value % 3 == 0 {
        return Cow::from("Fizz");
    } else {
        return Cow::from(value.to_string());
    }
}
