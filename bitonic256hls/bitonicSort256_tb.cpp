#include "bitonicSort256.h"
#include <cstdlib>

int main()
{
    din_t in[P];
    din_t out[P];

    srand((unsigned)time(0));

    for(int h=0; h<P; h++)
        {
                in[h] = rand() % 1000;
                cout << "numbers are: " << in[h] << endl;
        } 
        
    bitonicSort256(in, out);
    
    for(int i=0; i<P; i++){
	cout << out[i] << " ";
	}

	cout << endl;

    return 0;
}


