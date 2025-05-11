#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ANSI escape codes for colors
#define BLUE "\033[34m"
#define RESET "\033[0m"

void printMenu(const string& title, const string options[], int numOptions) {
    const int boxWidth = 36;
    const string margin = "          "; // 10 spaces alignment
    
    // Set blue color for entire menu
    cout << BLUE;
    
    // Top border
    cout << margin << "╔" << string(boxWidth, '═') << "╗\n";
    
    // Centered title
    int titleLen = title.length();
    int leftPad = (boxWidth - titleLen) / 2;
    int rightPad = boxWidth - titleLen - leftPad;
    cout << margin << "║" 
         << string(leftPad, ' ') << title << string(rightPad, ' ') 
         << "║\n";
    
    // Separator line
    cout << margin << "╠" << string(boxWidth, '═') << "╣\n";
    
    // Menu options
    for(int i = 0; i < numOptions; i++) {
        cout << margin << "║  " << left << setw(boxWidth-2) 
             << options[i] << "  ║\n";
    }
    
    // Bottom border
    cout << margin << "╚" << string(boxWidth, '═') << "╝" << RESET << endl;
}

int main() {
    // Enable ANSI escape codes on Windows
    system("");

    int choice;
    string menuTitle = "ROLE SELECTION MENU";
    string options[] = {
        "1. Junior",
        "2. Manager",
        "3. Director",
        "4. Executive",
        "5. Exit"
    };
    const int numOptions = 5;

    while(true) {
        // Clear screen (system-specific)
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        // Print the menu
        printMenu(menuTitle, options, numOptions);
        
        // Get user input
        cout << BLUE << "\n          Enter your choice (1-5): " << RESET;
        cin >> choice;

        // Handle input
        if(choice == 5) break;
        
        // Clear screen again
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        // Show selection result
        cout << BLUE << "\n          You selected: " << options[choice-1] << RESET << endl;
        
        // Pause before showing menu again
        cout << "\n          Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    cout << BLUE << "\n          Goodbye!" << RESET << endl;
    return 0;
}