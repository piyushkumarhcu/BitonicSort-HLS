#include "bitonicSort16.h"
#include <cstdlib>

int main()
{
    din_t in[N];
    din_t out[N];

    srand((unsigned)time(0));

    for(int h=0; h<N; h++)
        {
                in[h] = rand() % 100;
                cout << "numbers are: " << in[h] << endl;
        } 
        
    bitonicSort16(in, out);
    
    for(int i=0; i<N; i++){
	cout << out[i] << " ";
	}

	cout << endl;

    return 0;
}


