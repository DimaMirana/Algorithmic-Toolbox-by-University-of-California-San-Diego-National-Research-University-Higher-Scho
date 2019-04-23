#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;


void optimal_sequence(long long n)
{
    long long temp1,temp2,temp3,min_op,numbers = 0 ;
    vector <long long>sequence1(n+1);
    for (long long i =0; i<n+1; i++)
    {
        sequence1[i]=1000000;
        //cout<<"sequence[i]= "<<sequence[i]<<endl;
    }
    sequence1[0] = 0;
    sequence1[1] = 0;
    for(long long i=2; i<n+1; i++)
    {
        temp1=1000000;
        temp2=1000000;
        temp3=1000000;
        temp1=sequence1[i-1]+1;
        //cout<<"temp1 = "<<temp1<<endl;
        if(i%2==0)
        {
            temp2=sequence1[i/2]+1;
            //cout<<"temp2 = "<<temp2<<endl;
        }
        if(i%3==0)
        {
            temp3=sequence1[i/3]+1;
            //cout<<"temp3 = "<<temp3<<endl;
        }
        min_op = min(min(temp1,temp2),temp3);
        //cout<<"min_op= "<<min_op<<endl;
        sequence1[i] = min_op;
        //cout<<"sequence["<<i<<"]= "<<sequence[i]<<endl;

    }
    cout<<sequence1[n]<<endl;
    long long x = sequence1[n]+1;
    //cout<<"no of x = "<<x<<endl;

    vector <long long>sequence_of_numbers(x);

    while (n >= 1)
    {
        sequence_of_numbers.push_back(n);
        if (n % 3 == 0 && (sequence1[n]-1 == sequence1[n/3]))
        {
            n /= 3;
            //cout<<"n=n/3 "<<n<<endl;

        }
        else if (n % 2 == 0 &&(sequence1[n]-1 == sequence1[n/3]))
        {
            n /= 2;
            //cout<<"n=n/2 "<<n<<endl;
        }
        else
        {
            n = n - 1;
            //cout<<"n=n-1 "<<n<<endl;
        }
    }
    reverse(sequence_of_numbers.begin(), sequence_of_numbers.end());
    for(long long i=0;i<sequence_of_numbers.size();i++)
    {
        if(sequence_of_numbers[i]==0)
            break;
        cout<<sequence_of_numbers[i]<<" ";
    }

}

int main()
{
    long long n;
    std::cin >> n;
    optimal_sequence(n);
    /*std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        std::cout << sequence[i] << " ";
    }*/
}
