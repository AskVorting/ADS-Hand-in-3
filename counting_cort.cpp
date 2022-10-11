#include <vector>
#include <iostream>
using namespace std;

//counting sort
//sorts a vector by counting the number of times each element appears
class counting_sort
{
    private:
    //vector to be sorted
       vector<int> input;
       vector<int> output;

 
    public:
    //constructor
        void initialize_random_vector(int size , int max)
        {
            srand(time(0));
            for (int i = 0; i < size; i++)
            {
                input.push_back(rand() % max);
            }
        }

        //sorts the vector
        void countingSort()
        {
            for (int i = 0; i < input.size(); i++)
            {
                output[input[i]] = output[input[i]] + 1;
            }
        }

        //prints the vector
        void print()
        {
            for (int i = 0; i < input.size(); i++)
                {
                    cout << input[i] << " ";
                }
                cout << endl;

            for (int i = 0; i < output.size(); i++)
                {
                    cout << output[i] << " ";
                }
                cout << endl;
        }


} 

        



