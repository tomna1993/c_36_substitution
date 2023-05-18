#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encript_text(string plaintext, string key, const int textLength);

int main(int argc, string argv[])
{
	// Get CLA from user and check if it has 2 arguments
	if (argc != 2)
	{
		printf("Usage: ./build/substitution key");
		return 1;
	}

	// Get CLA string length and save it as a constant
	const int length = strlen(argv[1]);

	// Check the key argument to have 26 characters
	if (length != 26)
	{
		printf("Key must contain 26 characters.\n");
		return 1;
	}
	
	// Check the key argument to have just alphabetic characters
	for (int i = 0; i < length; i++)
	{
		if (!isalpha(argv[1][i]))	
		{
			printf("Key must contain just alphabetic characters.\n");
			return 1;
		}
	}

	// Check the key to not contain the same letter twice
	for (int i = 0; i < length; i++)	
	{
		// save the key[i] letter as lowercase
		char toTest_keyLower = tolower(argv[1][i]);
		// save the key[i] letter as uppercase
		char toTest_keyUpper = toupper(argv[1][i]);

		// Debug toTest_keyLower, toTest_keyUpper 
		// printf("LowerKey: %c, UpperKey: %c\n", toTest_keyLower, toTest_keyUpper);

		// Iterate through the key string and compare the saved letter
		// with all other letters; This checks that each letter is included just once
		for (int j = i+1; j < length; j++)
		{
			if (toTest_keyLower == argv[1][j] || toTest_keyUpper == argv[1][j])
			{
				printf("Key mustn't contain the same character more time!\n");
				return 1;
			}
		}
	}

	// Debug key
	// printf("key: %s\n", argv[1]);

	// Ask user for plaintext
	string plaintext = get_string("plaintext: ");

	// Convert the plaintext to ciphertext; be careful, the function will 
	// change the plaintext strin array!
	encript_text(plaintext, argv[1], length);

	// Print ciphertext
	printf("ciphertext: %s\n", plaintext);
}

// Define function to convert plaintext to ciphertext
void encript_text(string plaintext, string key, const int textLength)
{
	// Create constant for uppercase 'A' letter's decimnal value in ASCII
	const int A_ASCII = 65;
	// Create constant for lowercase 'a' letter's decimnal value in ASCII
	const int a_ASCII = 97;

	// If the character is not alphabetic, leave it unchanged

	// Iterate through the characters of plaintext
	for (int i = 0; i < textLength; i++)
	{
		// If character is a lowercase alphabetic character
		if (isalpha(plaintext[i]) && islower(plaintext[i]))
		{
			// Change the letter to its key equivalent
			// Change the letter to lowercase if it is uppercase in the key
			// f.e. plaintext[i] = 'a' = 97; key[0] = 'K'
			// key['a' - 97] = key[0] = 'K'
			// tolower(key[0]) = 'k'
			plaintext[i] = tolower(key[plaintext[i] - a_ASCII]);
		}
		
		// If character is a lowercase alphabetic character
		else if (isalpha(plaintext[i]) && isupper(plaintext[i]))
		{
			// Change the letter to its key equivalent
			// Change the letter to uppercase if it is lowercase in the key
			// f.e. plaintext[i] = 'K' = 75; key[10] = 'h'
			// key['K' - 65] = key[10] = 'h'
			// toupper(key[10]) = 'H'
			plaintext[i] = toupper(key[plaintext[i] - A_ASCII]);
		}
	}
}