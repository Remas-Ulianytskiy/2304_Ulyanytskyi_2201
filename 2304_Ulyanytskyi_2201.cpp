#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int get_user_value() {
    int value;
    cin >> value;
    return value;
}

void display_array_elements(const vector<int>& array) {
    cout << "{ ";
    for (const int& element : array) {
        cout << element << ' ';
    }
    cout << "}\n";
}

vector<int> create_user_array(const unsigned int array_size) {
    vector<int> result_array;

    for (int i = 0; i < array_size; ++i) {
        cout << "Enter " << i + 1 << '/' << array_size;
        cout << " element of array: ";
        result_array.push_back(get_user_value());
    }

    return result_array;
}

vector<int> create_random_array(const unsigned int array_size) {
    srand(time(0));
    const int MAX_RANGE = 100;
    const int MIN_RANGE = -100;
    vector<int> result_array;

    for (int i = 0; i < array_size; ++i) {
        result_array.push_back(rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE);
    }

    return result_array;
}

namespace Sort_by_Bubble {
    vector<int> sort_array(const vector<int>& array) {
        const unsigned int ARRAY_SIZE = array.size() - 1;
        vector<int> result_array = array;

        for (int i = 0; i < ARRAY_SIZE; ++i) {
            for (int j = 0; j < ARRAY_SIZE - i; ++j) {
                if (result_array[j] > result_array[j+1]) {
                    int temporary = result_array[j];
                    result_array[j] = result_array[j + 1];
                    result_array[j + 1] = temporary;
                }                
            }
        }

        return result_array;
    }
}

namespace Sort_By_Selection {
    vector<int> sort_array(const vector<int>& array) {
        const unsigned int ARRAY_SIZE = array.size();
        vector<int> result_array = array;        

        for (int i = 0; i < ARRAY_SIZE - 1; ++i) {
            int min_index = i;
            for (int j = i + 1; j < ARRAY_SIZE; ++j) {
                if (result_array[j] < result_array[min_index]) {
                    min_index = j;
                }
            }
            swap(result_array[i], result_array[min_index]);
        }

        return result_array;
    }
}

namespace Sort_By_Insertion {
    vector<int> sort_array(const vector<int>& array) {
        const unsigned int ARRAY_SIZE = array.size();
        vector<int> result_array = array;

        for (int i = 1; i < ARRAY_SIZE; ++i) {
            int current_element = result_array[i];
            int j = i - 1;

            while (j >= 0 && result_array[j] > current_element) {
                result_array[j + 1] = result_array[j];
                --j;
            }
            result_array[j + 1] = current_element;
        }

        return result_array;
    }
}

int main() {
    unsigned short user_menu_selection;
    bool exit_status = false;
    unsigned int array_size;
    vector<int> random_array;
    vector<int> user_array;
    vector<int> result_array;
    const vector<int> example_array = { 7, 1, 4, 26, 19, -1, 6 };

    cout << "Sorting Algorithms";
    do
    {        
        cout << "\n1 - for choice Bubble Sort\n";
        cout << "2 - for choice Selection Sort\n";
        cout << "3 - for choice Insertion Sort\n";
        cout << "0 - for Exit\n";
        cout << "Enter: ";

        user_menu_selection = get_user_value();

        if (user_menu_selection == 0) {
            exit_status = true;
            cout << "Exit";
        }
        else if (user_menu_selection > 0) {
            unsigned short operation = user_menu_selection;

            cout << "\n1 - for use example array for sort\n";
            cout << "2 - for create random array and sort\n";
            cout << "3 - for create user array and sort\n";
            cout << "0 - for back to main menu\n";
            cout << "Enter: ";

            user_menu_selection = get_user_value();

            switch (user_menu_selection)
            {
            case 0:
                cout << "Back to main menu\n";
                break;
            case 1:
                cout << "\nExample array ";
                display_array_elements(example_array);
                if (operation == 1)
                    result_array = Sort_by_Bubble::sort_array(example_array);
                if (operation == 2)
                    result_array = Sort_By_Selection::sort_array(example_array);
                if (operation == 3)
                    result_array = Sort_By_Insertion::sort_array(example_array);
                break;
            case 2:
                cout << "Enter array size: ";
                array_size = get_user_value();
                random_array = create_random_array(array_size);
                cout << "\nRandom array ";
                display_array_elements(random_array);

                if (operation == 1)
                    result_array = Sort_by_Bubble::sort_array(example_array);
                if (operation == 2)
                    result_array = Sort_By_Selection::sort_array(create_random_array(array_size));
                if (operation == 3)
                    result_array = Sort_By_Insertion::sort_array(create_user_array(array_size));
                break;
            case 3:
                cout << "Enter array size: ";
                array_size = get_user_value();
                if (operation == 1)
                    result_array = Sort_by_Bubble::sort_array(example_array);
                if (operation == 2)
                    result_array = Sort_By_Selection::sort_array(create_random_array(array_size));
                if (operation == 3)
                    result_array = Sort_By_Insertion::sort_array(create_user_array(array_size));
                break;
            default:
                cout << "Invalid input!";
                break;
            }

            cout << "Result array ";
            display_array_elements(result_array);
        }
        else {
            cout << "\nInvalid input!\n";
        }

    } while (!exit_status);

    return 0;
}