#include <iostream>
#include <vector>
#include <algorithm>
int BooksNumber = 0;
std::vector<std::string> BooksLabel;
char ChangeAgain;
void EnterBooks();
void ChangeBookName();
int main()
{
    std::cout << "\n==  Bookshop Management System ==\n\n";
    // Task 1. [ add and display books ]
    std::string UserName = "";
    std::cout << "Enter Your Name : ";
    std::cin >> UserName;
    std::cout << "You Have [ " << BooksNumber << " ] Books" << "\n";

    // =============
    std::string UserInput = "";
    std::cout << "Enter (Add) to Add Books : ";
    std::cin >> UserInput;
    if (UserInput == "Add")
    {
        EnterBooks();
        while (BooksNumber < 0)
        {
            std::cout << "Enter Valid Input\n";
            EnterBooks();
        }
        if (BooksNumber == 0)
        {
            std::cout << "No Books Will be Added.";
            return 0;
        }
        else if (BooksNumber > 0)
        {
            char confirm;
            std::cout << "Are You Sure You Want to Enter " << BooksNumber << " Books Into Your List? ( Y / N ) : ";
            std::cin >> confirm;
            if (confirm == 'Y')
            {
                std::cout << "\n\n";
                std::string booksLabel = "";
                for (int i = 1; i <= BooksNumber; i++)
                {
                    std::cout << "Enter Book Label Number [ " << i << " ]";
                    std::getline(std::cin, booksLabel);
                    BooksLabel.push_back(booksLabel);
                    booksLabel = "";
                }
                std::cout << "== You Entered These Books ==\n\n";
                for (int i = 0; i < BooksLabel.size(); i++)
                {
                    std::cout << i + 1 << " - " << BooksLabel[i] << "\n\n";
                }
                std::cout << "You Have [ " << BooksLabel.size() << " ] Books";

                // Task 2. [ change their books by implementing modifications to them ]
                std::cout << "Are You Willing To Bring Modifications To Your Books List? ( Y / N ) : ";
                char confirm_Modifications;
                std::cin >> confirm_Modifications;
                if (confirm_Modifications == 'Y')
                {
                    std::cout << "Change Book Name, Add New Book, Delete a Book ? ( Change / Add / Delete ) : ";
                    std::string UserOptionInput = "";
                    std::cin >> UserOptionInput;
                    std::cin.ignore();
                    std::vector<std::string> UserOptions{"Change", "Add", "Delete"};

                    // Change Book Name
                    if (UserOptionInput == UserOptions[0])
                    {
                        std::cout << "You Want to Change Book Name ? ( Y / N ) : ";
                        char Y_N;
                        std::cin >> Y_N;
                        if (Y_N == 'Y')
                        {
                            std::cout << "Enter Book Number You Want to Change ( Start From Book Number 0 - The Last Book ) : ";
                            int UserInputBookNumber = 0;
                            std::cin >> UserInputBookNumber;
                            std::string newName = "";
                            std::cout << "Enter New Name For Book Number [ " << UserInputBookNumber << " ] : ";
                            std::getline(std::cin, newName);
                            if (newName.length())
                            {
                                BooksLabel[UserInputBookNumber] = newName;
                            }
                            std::cout << "\n\n== After ==\n\n";
                            for (int i = 0; i < BooksLabel.size(); i++)
                            {
                                std::cout << i + 1 << " - " << BooksLabel[i] << std::endl;
                            }
                        }
                        else if (Y_N == 'N')
                        {
                            std::cout << "Thanks For Using Our Program!";
                        }
                    }

                    // Add Books
                    if (UserOptionInput == UserOptions[1])
                    {
                        std::cout << "You Want to Add New Book ? ( Y / N ) : ";
                        char Y_N;
                        std::cin >> Y_N;
                        if (Y_N == 'Y')
                        {
                            std::cout << "Enter Book Name : ";
                            std::string OneMoreBook = "";
                            std::getline(std::cin, OneMoreBook);
                            std::cout << "You Sure You Want to Add ";
                            std::cout << OneMoreBook;
                            std::cout << " to The List? ( Y / N ) : ";
                            char addBook;
                            std::cin >> addBook;
                            std::cin.ignore();
                            if (addBook == 'Y')
                            {
                                BooksLabel.push_back(OneMoreBook);
                                for (int i = 0; i < BooksLabel.size(); i++)
                                {
                                    std::cout << i + 1 << " - " << BooksLabel[i] << "\n\n";
                                }
                            }
                            else if (Y_N == 'N')
                            {
                                std::cout << "Thanks For Using Our Program!";
                            }
                        }
                    }

                    // Delete Books
                    else if (UserOptionInput == UserOptions[2])
                    {
                        std::cout << "You Want to Delete a Book ? ( Y / N ) : ";
                        char Y_N;
                        std::cin >> Y_N;
                        std::cin.ignore();
                        if (Y_N == 'Y')
                        {
                            std::cout << "Type The Book Number You Want to Delete ( Start From Book Number 0 - The Last Book ) : ";
                            int UserInputBookNumber = 0;
                            std::cin >> UserInputBookNumber;
                            std::cin.ignore();

                            std::cout << "You Sure You Want to Delete " << BooksLabel[UserInputBookNumber] << " From The List? ( Y / N ) : ";
                            char AskUser_for_Confirmation;
                            std::cin >> AskUser_for_Confirmation;
                            std::cin.ignore();
                            if (AskUser_for_Confirmation == 'Y')
                            {
                                BooksLabel.erase(BooksLabel.begin() + UserInputBookNumber);
                                for (int i = 0; i < BooksLabel.size(); i++)
                                {
                                    std::cout << BooksLabel[i] << std::endl;
                                }
                            }
                            std::cout << "DONE!" << std::endl;
                            for (int i = 0; i < BooksLabel.size(); i++)
                            {
                                std::cout << i + 1 << " - " << BooksLabel[i] << "\n\n";
                            }
                        }
                        else if (Y_N == 'N')
                        {
                            std::cout << "Thanks For Using Our Program!";
                        }
                    }
                }
                else if (confirm_Modifications == 'N')
                {
                    std::cout << "Thanks For Using Our Program!";
                }
            }
            else if (confirm == 'N')
            {
                std::cout << "Exit";
            }
            std::cout << "\n\n";
        }
    }
    // =============
    return 0;
}
void EnterBooks()
{
    std::cout << "How Many Books You Want to Add : ";
    std::cin >> BooksNumber;
}
void ChangeBookName()
{
    std::cout << "Enter Book Number : ";
    int BookNumber = 0;
    std::cin >> BookNumber;
    std::cin.ignore();
    std::cout << "Enter New Book Name : ";
    std::string NewBookName = "";
    std::getline(std::cin, NewBookName);
    BooksLabel[BookNumber] = NewBookName;
    std::cout << "New Name Is : " << BooksLabel[BookNumber] << "\n\n";
}
