#include "bitonicSort128.h"
#include <cstdlib>

int main()
{
    din_t in[O];
    din_t out[O];

    srand((unsigned)time(0));

    for(int h=0; h<O; h++)
        {
                in[h] = rand() % 200;
                cout << "numbers are: " << in[h] << endl;
        } 
        
    bitonicSort128(in, out);
    
    for(int i=0; i<O; i++){
	cout << out[i] << " ";
	}

	cout << endl;

    return 0;
}


