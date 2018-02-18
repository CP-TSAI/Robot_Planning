#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

pair<int, int> BlankTileLocation(vector<vector<int>>&);
void swap(vector<vector<int>>&, pair<int, int>, pair<int, int>);
void show_solution(vector<int>&, map<int, vector<vector<int>>>&);


/**********  You can define the INITIAL and FINAL state here *********/
vector<vector<int>> initial = {{7, 5, 4}, 
							   {0, 3, 2}, 
							   {8, 1, 6}}; 

vector<vector<int>> final = {{1, 2, 3}, 
							 {4, 5, 6}, 
							 {7, 8, 0}};
/********************************************************************/


int main(){
	// use a hash_map to save the repeated state
	set<vector<vector<int>>> repeated = {initial};

	// record the number of each matrix
	int number = 2;

	// self #, father #
	map<int, int> node_info;
	node_info.insert(pair<int, int> (1, 0));

	// <self #, state> and <state, self #>
	map<int, vector<vector<int>>> num_state; 
	num_state.insert(pair<int, vector<vector<int>>> (1, initial));
	
	map<vector<vector<int>>, int> state_num;
	state_num.insert(pair<vector<vector<int>>, int> (initial, 1));

	// BFS 
	queue<vector<vector<int>>> q;
	q.push(initial);

	// the action set defines: LEFT / RIGHT / UP / DOWN
	vector<pair<int, int>> actions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
	
	bool isOver = 0;
	while(!q.empty()){
		vector<vector<int>> tmp = q.front(); q.pop();
		int father_number = state_num[tmp];
		
		// get the position of the zero point
		pair<int, int> blank_location = BlankTileLocation(tmp);

		for(int i = 0; i < 4; i++){
			int row_offset = blank_location.first + actions[i].first;
			int col_offset = blank_location.second + actions[i].second;

			vector<vector<int>> next = tmp;
			
			if(row_offset >= 0 && row_offset <= 2 && col_offset >= 0 && col_offset <= 2){
				swap(next, blank_location, {row_offset, col_offset});
				auto iter = repeated.find(next);
				if(iter == repeated.end()){ // it never appears!
					state_num[next] = number;
					num_state[number] = next;
					node_info[number] = father_number;
					q.push(next);
					repeated.insert(next);
					number++;
				}
				if(next == final) isOver = 1;
			}
		}
		if(isOver) break;
	}

	// trace back the process by finding their father node
	int child_number = state_num[final];
	vector<int> trace = {child_number};
	while(1){
		int father_number = node_info[child_number];
		trace.push_back(father_number);
		if(father_number == 1) break;
		child_number = father_number;
	}

	// from final to initial, trace back the process
	show_solution(trace, num_state);
	
	cout << "the total step is " << trace.size() << endl;
	cout << "the total node number is " << num_state.size() << endl; 
	return 0;
}

void show_solution(vector<int> &trace, map<int, vector<vector<int>>> &num_state){
	int step_num = 1;
	for(auto iter = trace.rbegin(); iter != trace.rend(); iter++){
		vector<vector<int>> matrix = num_state[*iter];
		cout << "step " << step_num << ":  " << endl;
		step_num++;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				cout << matrix[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

// swap the element of the matrix
void swap(vector<vector<int>> &matrix, pair<int, int> start, pair<int, int> target){
	int tmp = matrix[start.first][start.second];
	matrix[start.first][start.second] = matrix[target.first][target.second];
	matrix[target.first][target.second] = tmp;
}


// return the position of zero point
pair<int, int> BlankTileLocation(vector<vector<int>> &matrix){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(matrix[i][j] == 0) return {i, j};
		}
	}
}
