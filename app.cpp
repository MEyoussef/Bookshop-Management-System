#include <iostream>
#include <vector>
int BooksNumber = 0;
void EnterBooks();
int main()
{
    std::cout << "\n==  Bookshop Management System ==\n\n";
    // Task 1. [ add and display books ]
    std::string UserName = "";
    std::string UserInput = "";
    std::cout << "Enter Your Name : ";
    std::cin >> UserName;
    std::cout << "You Have [ ";
    std::cout << BooksNumber;
    std::cout << " ] Books\n";

    // =============
    std::cout << "Enter *Add* to Add Books : ";
    std::cin >> UserInput;
    if (UserInput == "Add")
    {
        std::vector<std::string> BooksLabel;
        EnterBooks();
        while (BooksNumber < 0)
        {
            std::cout << "Enter Valid Input\n";
            EnterBooks();
        }
        if (BooksNumber == 0)
        {
            std::cout << "Thanks For Using Our Bookshop Management System.";
        }
        else if (BooksNumber > 0)
        {
            char confirm;
            std::cout << "The Books Number You Are About to Enter Can Not Be Changed. Are Your Sure You Want to Procced? ( Y / N ) : ";
            std::cin >> confirm;
            if (confirm == 'Y')
            {
                std::cout << "\n\n";
                std::string booksLabel = "";
                for (int i = 1; i <= BooksNumber; i++)
                {
                    std::cout << "Enter Book Label Number [ ";
                    std::cout << i;
                    std::cout << " ] : ";
                    std::getline(std::cin >> std::ws, booksLabel);
                    BooksLabel.push_back(booksLabel);
                    booksLabel = "";
                }
                std::cout << "== You Enter These Books ==\n\n";
                for (int i = 0; i < BooksLabel.size(); i++)
                {
                    std::cout << i << " - " << BooksLabel[i] << "\n\n";
                }
                std::cout << "You Have [ ";
                std::cout << BooksLabel.size();
                std::cout << " ] Books\n";

                // Task 2. [ change their books by implementing modifications to them ]
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