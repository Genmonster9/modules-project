#include <iostream>
#include <string>
#include <sstream>
using namespace std;

char getKeyCharacter();
string getString();
string maskCharacter(string theString, char keyCharacter);
string removeCharacter(string theString, char keyCharacter);
int countKey(string theString, char keyCharacter);

int main()
{
   char keyCharacter;
   string theString;

   keyCharacter = getKeyCharacter();
   theString = getString();

   cout << "\nString with key character, '" << keyCharacter << "' masked: \n"
      << maskCharacter(theString, keyCharacter) << endl;

   cout << "\nString with '" << keyCharacter << "' removed: \n"
      << removeCharacter(theString, keyCharacter) << endl;

   cout << "\n# of occurrences of key character, '" << keyCharacter << "': "
      << countKey(theString, keyCharacter) << endl;

   return 0;
}

char getKeyCharacter()
{
   string usrChar;
   char keyCharacter;

   do
   {
      cout << "Please enter a SINGLE character to act as key: ";
      getline(cin, usrChar);
   }
   while (usrChar.length() != 1);

   keyCharacter = usrChar[0];
   return keyCharacter;
}


string getString()
{
   string usrStr;
   const int MIN_LENGTH = 4,
      MAX_LENGTH = 600;

   do
   {
      cout << "Please enter a phrase or sentence >= " << MIN_LENGTH
         << " and <= " << MAX_LENGTH << " characters: ";
      getline(cin, usrStr);
   }
   while ((usrStr.length() < MIN_LENGTH) || (usrStr.length() > MAX_LENGTH));

   return usrStr;
}

string maskCharacter(string theString, char keyCharacter)
{
   char maskedChar = '*';

   for (int i = 0; i < theString.length(); i++)
   {
      if (theString[i] == keyCharacter)
         theString[i] = maskedChar;
   }

   return theString;
}

string removeCharacter(string theString, char keyCharacter)
{
   string returnString = "";
   for (int i = 0; i < theString.length(); i++)
   {
      if (theString[i] != keyCharacter)
         returnString = returnString + theString[i];
   }

   return returnString;
}

int countKey(string theString, char keyCharacter)
{
   int countKey = 0;
   for (int i = 0; i < theString.length(); i++)
   {
      if (theString[i] == keyCharacter)
         countKey ++;
   }

   return countKey;
}
