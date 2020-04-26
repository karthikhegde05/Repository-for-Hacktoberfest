Project for learning HTML and CSS

# PROBLEM: UP-DOWN SEQUENCES
## PROBLEM STATEMENT
A sequence of integers (a1,a2,…,ak) is said to be Up-down, if these inequalities hold true:
a1≤a2
a2≥a3
a3≤a4 and so on.

That is, every even-indexed element should be at least as large as its adjacent elements. And every odd-indexed element should be at most as large as its adjacent elements. Formally, a2i≥a2i+1 and a2i+1≤a2i+2,for all valid positions.
A subsegment is a consecutive portion of a sequence. That is, a subsegment of (b1,b2,…,bk) will be of the form (bi,bi+1,…,bj), for some i and j.
You are given a sequence (s1,s2,…,sn). You can insert at most one integer anywhere in this sequence. It could be any integer. After inserting an integer (or choosing not to), suppose you have the new sequence (t1,t2,…,tm). Note that m will either be n+1 or n. You want to maximize the length of the longest subsegment of (t1,t2,…,tm) which is Up-down, and output the length of that.

## CONSTRAINTS
1≤T≤2
1≤n≤10^6
1≤si≤10^9

## PSEUDO-CODE

int fill_dp_array(int dp[][2], vector &sequence, int i, int slope)
{
	if(i>=sequence.size())
		return 0;
	else if(dp[i][slope]>0)  
		return dp[i][slope];
	else
	{
		if(i==sequence.size()-1)
			dp[i][slope] = 1;
		else if(slope==0 && sequence[i]>sequence[i+1])
			dp[i][slope] = 1; //if length of up-down sequence from ith element onwards is to be found, but next element is lesser, so sequence broken, implies length is 1, i.e the element itself.
		else if(slope==1 && sequence[i]<sequence[i+1])
			dp[i][slope] = 1; //if length of down-up sequence from ith element onwards is to be found, but the next element is greater, so sequence broken, implies length is 1, i.e the element itself.
		else if(slope==0)
			dp[i][slope] = 1+fill_dp_array(dp, sequence, i+1, 1); //if from ith element onwards follows up-down sequence implies from (i+1)th element onwards must follow down-up sequence.
		else
			dp[i][slope] = 1+fill_dp_array(dp, sequence, i+1, 0); //if from ith element onwards follows down-up sequence implies from (i+1)th element onwards must follow up-down sequence.
		return dp[i][slope];
	}
};
## PROOF OF CORRECTNESS
In the ‘fill_dp_array’ function, dp[i][slope] gives us the length of the longest up-down or down-up sequence stating from index i. Slope=0 means its an up-down sequence and slope=1 means down-up sequence
•	if (i+1)th index is less than ith index and the slope is 0, the sequence is broken and the length is 1, that is the element itself.
•	if (i+1)th index is greater than ith index and the slope is 1, the sequence is broken and the length is 1, that is the element itself.
•	If the ith element follows up-down sequence and the slope is 0, the (i+1)th element onwards should also follow down-up sequence. So the recurrence follows.
•	If the ith element follows down-up sequence and the slope is 1, the (i+1)th element onwards should also follow up-down sequence. So the recurrence follows.
•	If ith element to (i+x)th is part of up-down sequence and (i+x+1)th element is down-up then we add a number in between to make the whole sequence Up-down. {where x is any positive integer} 
      Now for our final solution, we shall use dp[i][0] i.e. the length of the longest  up-down sequence from ith element and dp[i][1] i.e the length of the longest down-up sequence from ith element.
We iterate from i=0 to n.
In each iteration, we take x = dp[i][0] (the length of the longest  up-down sequence from ith element)
Now, there are 3 cases:
1.	If i+x is greater than or equal to n (where n is the length of the input array), then it implies that the up-down sequence is un broken from ith index till the end of array, thus we can add an integer and increase the length of the sequence by 1. Hence, solution will be x+1.
2.	if the longest up-down sequence from i has a length of x and x is odd thus breaking at i+x-1, then then i+x onwards, it follows another up-down sequence. Thus, we can add an integer in between so that the sequence is maintained, thus, solution is dp[i][0]+1+dp[i+x][0].
3.	If longest the up-down sequence from i has a length of x and x is even thus breaking at i+x-1, then then i+x onwards, it follows down-up sequence. Thus, we can add an integer in between so that the sequence is maintained, thus, solution is dp[i][0]+1+dp[i+x][1].
We then, in each iteration, take the max of current solution and the previous max solution.

Therefore, this algorithm covers all different cases which arise in the problem statement.

## TIME COMPLEXITY

fill_dp_array(int dp[1000007][2], vector<long long int>& sequence, int i, int slope):
•	if ith indexed element is unfilled and assuming the ith indexed element is the start of a sequence (either UD or DU)
o	but the (i+1)th indexed element is not part of that sequence, then put dp[i][slope]=1; implies complexity O(1)
o	if (i+1)thindexed element is part of that sequence then recurse the function for (i+1)thindexed element with proper parameters. (dp[i][slope] = 1+fill_dp_array(dp, sequence, i+1, <other slope>)) implies complexity O(n) [worst case]
•	If ithindex is filled, then it returns the index implies complexity O(1)


Main function’s for loop:
	
If at ith iteration, fill_dp_array(dp, sequence, i, slope), complexity is O(x) [i.e the fill_dp_array function recurses x times], then for the next x-1 iterations, the complexity of that function for that slope is O(1). Since in each iteration we call that function for both slopes, so when recursing the alternate slopes for each index is filled.

Hence worst case complexity:

O(n) + O(n) + (O(1)+O(1))*n-1 = 2*O(n) + 2*O(n-1) = O(n)

Therefore,
Time Complexity of the program: O(n)

## SPACE COMPLEXITY
Each subproblem only depended on it’s previous subproblem. That is the solution for an array of length n only depended on the solution for array of length n-1.
Thus to solve dp[n+1] we use dp[n]. Then we can remove the space for dp[n] and store dp[n+1] to solve further subproblems.
So Space Complexity of the algorithm will be 𝜃(1).


## INSTRUCTIONS TO EXECUTE
•	Open the terminal
•	Go to the folder where the file is stored
•	Execute the command “g++ <filename>.cpp” to compile the code
•	To run the code, execute the command “./a.out”
•	Then pass the inputs in the specified format.

### Input format:
•	The first line contains a single integer, T, which is the number of testcases. The description of each testcase follows.
•	The first line of every testcase contains a single integer, n, which is the number of integers in the original sequence.
•	The second line contains n integers: s1,s2,…,sns1,s2,…,sn, which forms the original sequence.


## DATA STRUCTURES USED
•	Vectors
•	Integer array

## CONTRIBUTION

1)C P Vikram Aditya (IMT2018085)  
•	Psuedo Code & Code
•	Time complexity Analysis
•	Instructions 
•	Test Case 3
2)Sairama Sashank Kadiyala(IMT2018064)
•	Pseudo Code & Code
•	Proof of Correctness
•	Space complexity Analysis
•	Test Case 4
•	Report

