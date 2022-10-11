#include <vector>
#include <iostream>
using namespace std;


//this file is mad to check my sort code because the code we got in the assigment had bugs in it , and it would not run on m computer
class sortClass
{
    public:
        
        void checkSort(const vector<int>& a) 
        {
            for (int i = 0; i < a.size() - 1; ++i) {
                if (a[i] >= a[i + 1]) {
                    cout << "Error at " << i << endl;
                }
            }
            cout << "Finished checksort \n" << endl;
        }


        template <typename AnyType>
        void permute(vector<AnyType>& a) 
        {
            for (int j = 1; j < a.size(); ++j) {
                swap(a[j], a[rand() % j]);
            }
        }
        
        
        void initialize_random_vector(int size)
        {
            for (int i = 0; i < size; i++)
            {
                input.push_back(i);
            }    
        }

        void Biggest_to_smalles(int size)
        {
            for (int i = 0; i < size; i++)
            {
                input.push_back(size - i);
            }    
        }
        


        //print vector
        void print()
        {
            for (int i = 0; i < input.size(); i++)
                {
                    cout << input[i] << " ";
                }
                cout << endl;
        }
        

    

        void selectionSort(vector <int>& vect)
        {
            for(int i = 0; i < vect.size(); i++)
            {
                    int min = i;
                    for(int j = i + 1; j < vect.size(); j++)
                    {
                        if(vect[j] < vect[min])
                            min = j;
                    }
                    
                    swap(vect[i], vect[min]);

            }
            
        }
        
        void selectionSortTime()
        {
            clock_t start = clock();
            selectionSort(input);
            clock_t end = clock();
            double time = (end - start) / (double) CLOCKS_PER_SEC;
            cout << "Time for selectionSort: " << time << endl;
        }

        


        vector <int> input;
        private:
};

int main()
{
    sortClass a;
    int size = 10000;
    cout <<"from 0 to " << size << endl;
    a.initialize_random_vector(size);
    a.selectionSortTime();
    a.checkSort(a.input);
    a.input.clear();

    cout <<"from " << size << " to 0" << endl;
    a.Biggest_to_smalles(size);
    a.selectionSortTime();
    a.checkSort(a.input);

    
    cout <<"permutes the vector" << endl;
    a.permute(a.input);
    a.selectionSortTime();
    a.checkSort(a.input);


    
    
    



    return 0;

}

