import random

def generate_password(num_letters: int, num_symbols: int, num_numbers: int) -> str:
    """
    Generate a random password containing letters, symbols, and numbers.
    
    Args:
        num_letters (int): Number of letters to include.
        num_symbols (int): Number of symbols to include.
        num_numbers (int): Number of digits to include.
    
        Returns:
        str: The final randomized password.
    """

    # Define the character sets
    letters = [
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    ]
    symbols = ['*', '?', '&', '^', '%', '@', '$', '#']
    numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

    # Randomly pick characters from each list
    chosen_letters = random.choices(letters, k=num_letters)
    chosen_symbols = random.choices(symbols, k=num_symbols)
    chosen_numbers = random.choices(numbers, k=num_numbers)

    # Combine all chosen characters
    password_list = chosen_letters + chosen_symbols + chosen_numbers

    # Shuffle to make the password unpredictable
    random.shuffle(password_list)

    # Join the shuffled list into a final string
    return ''.join(password_list)


def main():
    """Main function to get user input and generate the password."""
    print("Welcome to the Password Generator!")

    try:
        # Get user input for the number of characters
        num_letters = int(input("How many letters would you like in your password? "))
        num_symbols = int(input("How many symbols would you like? "))
        num_numbers = int(input("How many numbers would you like? "))
    except ValueError:
        # Handle invalid (non-integer) input
        print("Error: Please enter valid numbers only.")
        return

    # Generate the password
    password = generate_password(num_letters, num_symbols, num_numbers)

    # Display the result
    print("\nHere is your generated password:")
    print(password)


# Run the program only if executed directly
if __name__ == "__main__":
    main()
