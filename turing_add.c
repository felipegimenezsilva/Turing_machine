// Felipe Gimenez da Silva
// April, 2020 -> Quarentine of Covid

#include <stdio.h>

// example turing machine to 
// add 2 numbers with 4 bits
// ex : 1001 and 1010 -> 00010011
// tape with nambers
unsigned short int n[] =
{1,0,0,1,1,0,1,0};

// transition matrix
// matrix line = State
// matrix column = transition with 0 or 1
unsigned short int tm[13][2] =
{
	{ 0 , 1}, // state Q0 -> initial
	{ 2 , 2}, // state Q1
	{ 3 , 3}, // state Q2
	{ 4 , 4}, // state Q3
	{ 5 , 9}, // state Q4
	{ 6 , 6}, // state Q5
	{ 7 , 7}, // state Q6
	{ 8 , 8}, // state Q7
	{ 0 , 0}, // state Q8
	{ 6 ,10}, // state Q9
	{ 7 ,11}, // state Q10
	{ 8 ,12}, // state Q11
	{ 0 , 0}  // state Q12
};

// move matrix
// move the tape to right (-1)
// or to left (1)
// matrix line = state
// matrix column = transition
short int mm[13][2] = 
{
	{-1, 1}, // state Q0
	{ 1, 1}, // state Q1
	{ 1, 1}, // state Q2
	{ 1, 1}, // state Q3
	{-1,-1}, // state Q4
	{-1,-1}, // state Q5
	{-1,-1}, // state Q6
	{-1,-1}, // state Q7
	{-1,-1}, // state Q8
	{-1,-1}, // state Q9
	{-1,-1}, // state Q10
	{-1,-1}, // state Q11
	{-1,-1}  // state Q12
};

// rewrite matrix
// edit the tape
// matrix line = state
// matrix column = new value 
unsigned short int rw[13][2] =
{
	{0,0}, // state Q0
	{0,1}, // state Q1
	{0,1}, // state Q2
	{0,1}, // state Q3
	{1,0}, // state Q4
	{0,1}, // state Q5
	{0,1}, // state Q6
	{0,1}, // state Q7
	{0,1}, // state Q8
	{1,0}, // state Q9
	{1,0}, // state Q10
	{1,0}, // state Q11
	{1,0}  // state Q12
};

// alfabet = 0, 1
// index < 0 will stop the machine (space inside the tape)

int main()
{

	// input tape
	printf("Input Tape:\n");
	unsigned short int a = 0;
	for( a ; a < 8 ; a++ )
		printf( "%i" , n[a] );
	printf("\n\n");

	// initial position of tape
	short int i = 3 ;
	// initial state
	unsigned short int s = 0 ;
	// read value
	unsigned short int rd = 0;
	
	// tape != end
	while( i >= 0 )
	{
		
		// read tape
		rd = n[i] ;
		printf("State : Q%2i , Value: %i , ",s,n[i]);
		
		// update tape
		n[i] = rw[s][rd] ;
		printf(" New Value : %i , Tape position : %i , ",n[i],i);
		
		// move tape to "+1" or "-1"
		i += mm[s][rd] ;
		printf("Next Tape Position : %i , ",i);
		
		// transit state
		if (i >= 0) s = tm[s][rd];
		printf("Next State : %i\n",s);
	}
	
	// printing "result tape"
	printf("\nResult Tape:\n");
	for(i=0;i<8;i++)
	{
		printf("%i",n[i]);
	}
	printf("\n");

}
