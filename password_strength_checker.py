def check_password_strength(password):
    """
    Check the strength of a password based on various criteria
    Returns a score and feedback message
    """
    score = 0
    feedback = []
    
    # Check length
    if len(password) >= 12:
        score += 2
        feedback.append("Good length")
    elif len(password) >= 8:
        score += 1
        feedback.append("Acceptable length")
    else:
        feedback.append("Password too short")
    
    # Check for numbers
    if any(char.isdigit() for char in password):
        score += 1
        feedback.append("Contains numbers")
    else:
        feedback.append("Add numbers")
    
    # Check for uppercase letters
    if any(char.isupper() for char in password):
        score += 1
        feedback.append("Contains uppercase letters")
    else:
        feedback.append("Add uppercase letters")
    
    # Check for lowercase letters
    if any(char.islower() for char in password):
        score += 1
        feedback.append("Contains lowercase letters")
    else:
        feedback.append("Add lowercase letters")
    
    # Check for special characters
    special_chars = "!@#$%^&*()_+-=[]{}|;:,.<>?"
    if any(char in special_chars for char in password):
        score += 2
        feedback.append("Contains special characters")
    else:
        feedback.append("Add special characters")
    
    # Calculate strength based on score
    if score >= 6:
        strength = "Strong"
    elif score >= 4:
        strength = "Moderate"
    else:
        strength = "Weak"
    
    return strength, score, feedback

def main():
    print("Welcome to Password Strength Checker!")
    print("Enter a password to check its strength (or 'quit' to exit)")
    
    while True:
        password = input("\nEnter password: ")
        if password.lower() == 'quit':
            break
        
        strength, score, feedback = check_password_strength(password)
        
        print(f"\nPassword Strength: {strength}")
        print(f"Score: {score}/7")
        print("Feedback:")
        for item in feedback:
            print(f"- {item}")

if __name__ == "__main__":
    main()
