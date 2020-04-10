#include <stdio.h>
#include <stdbool.h>
bool IsWhitespace(char);
int main()
{
	int LengthOfWord[15]; //create an array store length of word
	char c = 0;
	char prevChar = 0;
	int wordLength = 0;
	int nwhite = 0;
	for(c = 0; c < 15; ++c)
	{
		LengthOfWord[c] = 0;
	}	
	
	do
	{
		c=getchar();
		if (IsWhitespace(c))
		{
			if (IsWhitespace(prevChar))
                // Ignore extra whitespace.
                ; // Null stmt.
            else
            {
            	// Prev char not whitespace.
                // Means end of word.
                // Store length in array.
                if(wordLength < 14)
                	++LengthOfWord[wordLength];
                else
                	++LengthOfWord[14];
                
                wordLength = 0;
			}
		}
		else
		{
			// Not whitespace, therefore not end of word.
        	// Increment counter for word length.
			++wordLength;
		}
		//set prevchar to current
		prevChar = c;
		
	}while(c != '\n' && c != EOF);
	
	printf("HISTOGRAM THE LENGTH OF WORDS\n");
	
	//counter
	int i;
	for(c = 1; c < 15; ++c)
	{
		printf("\n%d", c);
		for(i = 1; i <= LengthOfWord[c]; ++i)
		{
			printf("*");
		}
	}
	printf("\n\n");
	system("pause");
	return 0;
}
 bool IsWhitespace(char t)
{
     // Return true for whitespace chars.

     // Space.
     if (t == 32)
     return true;

     // Newline.
     if (t == 10)
           return true;

     // Tab.
     if (t == 9)
           return true;

     // If we get here, no whitespace.
     return false;
} // IsWhitespace
