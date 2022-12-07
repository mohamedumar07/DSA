#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Books
{
  char title[50];
  char authorName[50];
  int copies;
  int year;
 }Books;

void getBooksData(int noOfBooks, Books *b);
int returningBook(Books *b);
int issuingBook(Books *b);
void makingDecision(Books *b);
// void showUpdatedData(Books *b);
void searchBasedOnYear(Books *b);
void noOfCopies(Books *b);
void bookNameAndCopies(Books *b);
int noOfBooks ;
char title[50], authorName[50];

 int main()
{
  Books b[noOfBooks];
  printf("No of book's details to be entered: ");
  scanf("%d", &noOfBooks);
  getBooksData(noOfBooks, b);
  makingDecision(b);  //done

}

void noOfCopies(Books *b)
{//done
  bool found = false;
  printf("Enter the title of the book to see no. of copies available: ");
  getchar();
  gets(title, 50, stdin);
  for(int book = 0; book < noOfBooks; book++)
  {
    if(strcmp(b[book].title, title) == 0){
      found = true;
      printf("No. of copies of %s : %d", title, b[book].copies);
      break;
    }
  }
  if(found == false){
    printf("%s is not available in this library", title);
  }
}

void bookNameAndCopies(Books *b)
{//done
  for(int book = 0; book < noOfBooks; book++)
  {
    printf("Title of the book: %s\n", b[book].title);
    printf("No. of copies available %d\n", b[book].copies);
  }
}

void searchBasedOnYear(Books *b)
{//done
  int year;
  bool avail = false;
  printf("Enter the published year of books: ");
  scanf("%d", &year);
  printf("Books published in the  year of %d: \n", year);
  for(int book = 0; book < noOfBooks; book++)
  {
    if(b[book].year == year)
    {
      avail = true;
      printf("Title of the Book: %s\n", b[book].title);
      printf("Author name: %s\n", b[book].authorName);
    }
  }
  if(avail == false)
  {
    printf("No books were published at the time.");
  }
}

void getBooksData(int noOfBooks, Books *b)
{ //done
  for(int book = 0; book < noOfBooks; book++)
  {
    printf("Enter the details of book no %d\n", (book+1));
    printf("Enter book title: ");
    getchar();
    gets(b[book].title);
    printf("Enter author name: ");
    gets(b[book].authorName);
    printf("No of copies: ");
    scanf("%d", &b[book].copies);
    printf("Year the book was published: ");
    scanf("%d", &b[book].year);
  }
}

void makingDecision(Books *b)
{//done
  int choice;
  printf("LIBRARY MANAGEMENT SYSTEM\n");
  printf("\t1.To take a book\n\t2. To return a book\n\t3. To list books based on year\n\t4. To list no. of copies of a certain book available\n\t5. Listing all book names in the library with the total no of copies\n\t0. To quit\n");
  do{
  printf("\nEnter your choice: ");
  scanf("%d", &choice);
  switch (choice) {
    case 0:
          printf("You exited the library.\n");
          break;
    case 1:
          issuingBook(b); //change name of decrementCopies
          continue;
    case 2:
          returningBook(b); //change name of incrementCopies
          continue;
    case 3:
          searchBasedOnYear(b);
          continue;
    case 4:
          noOfCopies(b);
          continue;
    case 5:
          bookNameAndCopies(b);
          continue;
    default:
          printf("Enter valid choice.\n");
          continue;
  }
}while(choice != 0);
}

void showUpdatedData(Books *b)
{
  printf("Updated data: \n");
  for(int book = 0; book < noOfBooks; book++)
  {
    printf("Title: %s, Author Name: %s, Copies: %d, Year: %d\n", b[book].title, b[book].authorName, b[book].copies, b[book].year);
  }
}

int issuingBook(Books *b)
 {//done
   printf("Enter the title of the book you want to take: ");
   getchar();
   gets(title, 50, stdin);
   for(int book = 0; book < noOfBooks; book++)
   {
     if(strcmp(b[book].title, title) == 0)
     {
       b[book].copies--;
     }
   }
 }

 int returningBook(Books *b)
 {//done
   printf("Enter the title of the book you want to return: ");
   getchar();
   gets(title, 50, stdin);
   for(int book = 0; book < noOfBooks; book++)
   {
     if(strcmp(b[book].title, title) == 0)
     {
       b[book].copies++;
     }
   }
 }
