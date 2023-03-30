#include <stdio.h>
#include <stdlib.h>


char * please_enter_your_username(void); // Should both be at least 20 char's due to password safety considerations.
char * please_enter_your_password(void); // See: https://blog.knowbe4.com/we-recommend-passwords-over-20-characters


// main //


int main()
{
  char * username = please_enter_your_username();
  char * password = please_enter_your_password();
  
  
  printf("\n");
  printf("user: %s\n", username);
  printf("pass: %s\n", password);
  
  
  // Clean up! Don't you forget now!
  free(username);
  free(password);
  
  return 0;
}




// functions //


char * please_enter_your_username(void)
{
  printf("\nusername: ");
  
  const int LOW_USERNAME_CHARACTER_LIMIT = 0;
  const int TOP_USERNAME_CHARACTER_LIMIT = 30;
  int       index = 0;
  
  char * username = malloc(sizeof(char) * TOP_USERNAME_CHARACTER_LIMIT);
  char c = ' '; 
  
  while ( (c = getchar()) != '\n' )
  {
    if (((int)c) == EOF) { break; }
    
    if (index >= LOW_USERNAME_CHARACTER_LIMIT && index < TOP_USERNAME_CHARACTER_LIMIT)
    {
      username[index] = c;
      ++index;
    }
  }
  
  return username;
}


char * please_enter_your_password(void)
{
  printf("password: ");
  
  const int LOW_PASSWORD_CHARACTER_LIMIT = 0;
  const int TOP_PASSWORD_CHARACTER_LIMIT = 30;
  int       index = 0;
  
  char * password = malloc(sizeof(char) * TOP_PASSWORD_CHARACTER_LIMIT);
  char c = ' '; 
  
  while ( (c = getchar()) != '\n' )
  {
    if (((int)c) == EOF) { break; }
    
    if (index >= LOW_PASSWORD_CHARACTER_LIMIT && index < TOP_PASSWORD_CHARACTER_LIMIT)
    {
      password[index] = c;
      ++index;
    }
  }
  
  return password;
}
