#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encript_text(string plaintext, string key);

int main(int argc, string argv[])
{
	// Get CLA from user and check if it has 2 arguments
	if (argc != 2)
	{
		printf("Usage: ./build/substitution key");
		return 1;
	}

	int length = strlen(argv[1]);

	if (length > 26)
	{
		printf("Key must contain 26 alphabetic characters.\n");
		return 1;
	}
	
	// Check the key argument to have 26 alphabetic characters
	for (int i = 0; i < length; i++)
	{
		if (!isalpha(argv[1][i]))	
		{
			printf("Key must contain 26 alphabetic characters.\n");
			return 1;
		}
	}

	printf("ciphertext: %s\n", argv[1]);

	// Ask user for a plaintext
	string plaintext = get_string("plaintext: ");

	// Convert the plaintext to ciphertext
	encript_text(plaintext, argv[1]);

	// Print ciphertext
	printf("ciphertext: %s\n", plaintext);
}

// Define function to convert plaintext to ciphertext
void encript_text(string plaintext, string key)
{

}