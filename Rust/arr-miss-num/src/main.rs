use std::io;

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input)
        .expect("Failed to read line");

    let test_cases: usize = input.trim().parse()
        .expect("Please type a number!");

    let mut missing_numbers: Vec<i32> = Vec::new();

    for _ in 0..test_cases {
        input = String::new();

        io::stdin().read_line(&mut input)
            .expect("Failed to read line");

        input = String::new();

        io::stdin().read_line(&mut input)
            .expect("Failed to read line");
        
        let arr_vec: Vec<i32> = input
            .split(' ')
            .map(|x| x.trim().parse::<i32>().expect("Invalid item in array"))
            .collect();

        missing_numbers.push(arr_miss_num(&arr_vec));
    }

    for missing_number in &missing_numbers {
        print!("{}", missing_number);

        if missing_numbers.last().unwrap() != missing_number {
            print!(" ");
        }
    }   
}

fn arr_miss_num(original_arr: &[i32]) -> i32 {
    let mut arr = original_arr;
    let mut index_offset: usize = 0;

    if original_arr.len() == 1 {
        return 1;
    }

    while arr.len() > 1 {
        let index = arr.len() / 2;
        let expected_number = index_offset as i32 + index as i32 + 1;

        if arr[index] == expected_number {
            arr = &arr[index + 1 .. arr.len()];
            index_offset = index_offset + index + 1;
        } else {
            arr = &arr[0 .. index];
        }
    }

    let missing_number: i32;

    if index_offset == 0 {
        if original_arr[index_offset + 1] - original_arr[index_offset] > 1 {
            missing_number = original_arr[index_offset] + 1;
        } else {
            missing_number = 1;
        }
    } else {
        if index_offset >= original_arr.len() - 1 {
            missing_number = original_arr[original_arr.len() - 1] - 1;
        } else {
            if original_arr[index_offset + 1] - original_arr[index_offset] > 1 {
                missing_number = original_arr[index_offset] + 1;
            } else {
                missing_number = original_arr[index_offset] - 1;
            }
        }
    }

    missing_number
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn right_miss_arr_test() {
        let arr = [1, 2, 3, 4, 5, 6, 7, 8, 10];
        let result = arr_miss_num(&arr);
        assert_eq!(9, result);
    }

    #[test]
    fn right_miss_perm1_arr_test() {
        let arr = [1, 2, 3, 4, 5, 6, 7, 9, 10];
        let result = arr_miss_num(&arr);
        assert_eq!(8, result);
    }

    #[test]
    fn one_item_arr_test() {
        let arr = [2];
        let result = arr_miss_num(&arr);
        assert_eq!(1, result);
    }

    #[test]
    fn right_miss_perm2_arr_test() {
        let arr = [1, 2, 3, 4, 5, 6, 8, 9, 10];
        let result = arr_miss_num(&arr);
        assert_eq!(7, result);
    }

    #[test]
    fn left_miss_perm1_arr_test() {
        let arr = [1, 2, 4, 5, 6, 7, 8, 9, 10];
        let result = arr_miss_num(&arr);
        assert_eq!(3, result);
    }

    #[test]
    fn right_miss_large_arr_test() {
        let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19];
        let result = arr_miss_num(&arr);
        assert_eq!(13, result);
    }

    #[test]
    fn middle_miss_arr_test() {
        let arr = [1, 2, 3, 4, 5, 7, 8, 9, 10];
        let result = arr_miss_num(&arr);
        assert_eq!(6, result);
    }

    #[test]
    fn left_miss_arr_test() {
        let arr = [1, 3, 4, 5, 6, 7, 8, 9, 10];
        let result = arr_miss_num(&arr);
        assert_eq!(2, result);
    }

    #[test]
    fn left_miss_large_arr_test() {
        let arr = [1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20];
        let result = arr_miss_num(&arr);
        assert_eq!(3, result);
    }    

    #[test]
    fn first_miss_arr_test() {
        let arr = [2, 3, 4, 5, 6, 7, 8, 9, 10];
        let result = arr_miss_num(&arr);
        assert_eq!(1, result);
    }

    #[test]
    fn small_arr_test() {
        let arr = [1, 2, 3, 5];
        let result = arr_miss_num(&arr);
        assert_eq!(4, result);
    }
}
