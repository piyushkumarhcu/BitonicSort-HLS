#include "bitonicSort64.h"
#include <cstdlib>

int main()
{
    din_t in[M];
    din_t out[M];

    srand((unsigned)time(0));

    for(int h=0; h<M; h++)
        {
                in[h] = rand() % 100;
                cout << "numbers are: " << in[h] << endl;
        } 
        
    bitonicSort64(in, out);
    
    for(int i=0; i<M; i++){
	cout << out[i] << " ";
	}

	cout << endl;

    return 0;
}


