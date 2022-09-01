#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int qweasd = 0;

bool game = true;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
char s = 219;
int n = 8;
string** board = new string * [n];
int player = 1; // {1} - blue, {-1} - red
int checked_x = 0;
int checked_y = 7;
int checked_x_end = -1;
int checked_y_end = -1;

int king_r_x = 4;
int king_r_y = 0;
int king_b_x = 4;
int king_b_y = 7;

int warning = 0; //{1] - blue, {-1} - red
int warning_x = -1;
int warning_y = -1;
string warning_symbol = "0";
char warning_king = 'n';

void set_board() {
	board[0] = new string[n]{ "Ur", "Jr", "Yr", "Qr", "Kr", "Yr", "Jr", "Ur" };
	board[1] = new string[n]{ "ir", "ir", "ir", "ir", "ir", "ir", "ir", "ir" };

	board[2] = new string[n]{};
	board[3] = new string[n]{};
	board[4] = new string[n]{};
	board[5] = new string[n]{};

	board[n - 2] = new string[n]{ "ib", "ib", "ib", "ib", "ib", "ib", "ib", "ib" };
	board[n - 1] = new string[n]{ "Ub", "Jb", "Yb", "Qb", "Kb", "Yb", "Jb", "Ub" };

}



void Blue() {
	SetConsoleTextAttribute(h, 1);
}
void Red() {
	SetConsoleTextAttribute(h, 4);
}
void Green() {
	SetConsoleTextAttribute(h, 2);
}
void Yellow() {
	SetConsoleTextAttribute(h, 14);
}
void White() {
	SetConsoleTextAttribute(h, 7);
}

void print_white_blank(int i, int j) {
	
	if (i == checked_y && j == checked_x) {
		Green();
		s = '#';
	}
	if (i == checked_y_end && j == checked_x_end) {
		Yellow();
		s = '#';
	}
	
	//Warning
	if (warning == 1 && i == king_b_y && j == king_b_x){
		Red();
	}
	if (warning == -1 && i == king_r_y && j == king_r_x){
		Red();
	}
	
	cout << s << s << s << s << s;
	White();
	s = 219;
}
void print_black_blank(int i, int j) {
	char temp = ' ';
	
	if (i == checked_y && j == checked_x) {
		Green();
	}
	if (i == checked_y_end && j == checked_x_end) {
		Yellow();
	}
	
	//Warning
	if (warning == 1 && i == king_b_y && j == king_b_x){
		Red();
		temp = s;
	}
	if (warning == -1 && i == king_r_y && j == king_r_x){
		Red();
		temp = s;
	}
	
	if (i == checked_y && j == checked_x) {
		temp = '#';
	}
	if (i == checked_y_end && j == checked_x_end) {
		temp = '#';
	}
	
	cout << temp << temp << temp << temp << temp;
	White();
}

void print_white(int i, int j) {
	
	if (i == checked_y && j == checked_x) {
		Green();
		s = '#';
	}
	if (i == checked_y_end && j == checked_x_end) {
		Yellow();
		s = '#';
	}
	//Warning
	if (warning == 1 && i == king_b_y && j == king_b_x){
		Red();
	}
	if (warning == -1 && i == king_r_y && j == king_r_x){
		Red();
	}
	cout << s << s;

	if (board[i][j] != "") {
		if (board[i][j][1] == 'r') Red();
		if (board[i][j][1] == 'b') Blue();
		cout << board[i][j][0];
		White();
	}
	else cout << s;
	if (i == checked_y && j == checked_x) Green();
	if (i == checked_y_end && j == checked_x_end) Yellow();
	//Warning
	if (warning == 1 && i == king_b_y && j == king_b_x){
		Red();
	}
	if (warning == -1 && i == king_r_y && j == king_r_x){
		Red();
	}
	cout << s << s;
	s = 219;
	White();
}
void print_black(int i, int j) {
	char temp = ' ';
	if (i == checked_y && j == checked_x) {
		Green();
	}
	if (i == checked_y_end && j == checked_x_end) {
		Yellow();
	}
	//Warning
	if (warning == 1 && i == king_b_y && j == king_b_x){
		Red();
		temp = s;
	}
	if (warning == -1 && i == king_r_y && j == king_r_x){
		Red();
		temp = s;
	}
	
	if (i == checked_y && j == checked_x) {
		temp = '#';
	}
	if (i == checked_y_end && j == checked_x_end) {
		temp = '#';
	}
	
	cout << temp << temp;

	if (board[i][j] != "") {
		if (board[i][j][1] == 'r') Red();
		if (board[i][j][1] == 'b') Blue();
		cout << board[i][j][0];
		White();
	}
	else cout << temp;
	if (i == checked_y && j == checked_x) Green();
	if (i == checked_y_end && j == checked_x_end) Yellow();
	//Warning
	if (warning == 1 && i == king_b_y && j == king_b_x){
		Red();
	}
	if (warning == -1 && i == king_r_y && j == king_r_x){
		Red();
	}
	cout << temp << temp;
	White();
}

void print_board() {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		temp = 0;
		if (i % 2 == 1) temp = 1;
		for (int j = 0; j < n; j++) {
			if (temp % 2 == 0)
				print_white_blank(i, j);
			else
				print_black_blank(i, j);
			temp++;
		}
		cout << "   |";
		cout << endl;
		temp -= 8;
		for (int j = 0; j < n; j++) {
			if (temp % 2 == 0)
				print_white(i, j);
			else
				print_black(i, j);
			temp++;
		}
		cout << "   | " << 8 - i;
		cout << endl;
		temp -= 8;
		for (int j = 0; j < n; j++) {
			if (temp % 2 == 0)
				print_white_blank(i, j);
			else
				print_black_blank(i, j);
			temp++;
		}
		cout << "   |";
		cout << endl;
	}
}

//i
bool move_i(int d_start, int l_start_int, int d_end, int l_end_int, bool check=false) {
	string* current = &board[d_start][l_start_int];
	string* end = &board[d_end][l_end_int];
	bool flag = false;
	if ((*current)[1] == 'b') {
		if (d_end - d_start == -1 && l_end_int == l_start_int) {
			if (*end == "") {
				flag = true;

			}
		}
		if (d_end - d_start == -2 && l_end_int == l_start_int && d_start == 6) {
			if (*end == "") {
				flag = true;

			}
		}
		if (d_end - d_start == -1 && abs(l_end_int - l_start_int) == 1) {
			if (*end != "" && (*end)[1] != 'b') {
				flag = true;
			}
		}
		if (!flag) {
			return false;
		}
		if (d_end == 0 && (!check)) {
			*current = "Qb";
		}
	}
	else {
		if (d_end - d_start == 1 && l_end_int == l_start_int) {
			if (*end == "") {
				flag = true;
			}
		}
		if (d_end - d_start == 2 && l_end_int == l_start_int && d_start == 1) {
			if (*end == "") {
				flag = true;

			}
		}
		if (d_end - d_start == 1 && abs(l_end_int - l_start_int) == 1) {
			if (*end != "" && (*end)[1] != 'r') {
				flag = true;
			}
		}
		if (!flag) {
			return false;
		}
		if (d_end == 7 && (!check)) {
			*current = "Qr";
		}
	}
	
	if (!check){
		*end = *current;
		*current = "";
	}
	return true;
}

//U
bool move_U(int d_start, int l_start_int, int d_end, int l_end_int, bool check=false) {
	string* current = &board[d_start][l_start_int];
	string* end = &board[d_end][l_end_int];

	if (player == 1 && (*end).length() > 0 && (*end)[1] == 'b') return false;
	if (player == -1 && (*end).length() > 0 && (*end)[1] == 'r') return false;
	if (d_end == d_start) {
		if (l_start_int > l_end_int) {
			for (int i = l_start_int - 1; i > l_end_int; i--) {
				if (board[d_start][i] != "") return false;
			}
		}
		else {
			for (int i = l_start_int + 1; i < l_end_int; i++) {
				if (board[d_start][i] != "") return false;
			}
		}
	}
	if (l_end_int == l_start_int) {

		if (d_start > d_end) {
			for (int i = d_start - 1; i > d_end; i--) {
				if (board[i][l_start_int] != "") return false;
			}
		}
		else {
			for (int i = d_start + 1; i < d_end; i++) {
				if (board[i][l_start_int] != "") return false;
			}
		}

	}
	if (!check){
		*end = *current;
		*current = "";
	}
	return true;
}

//Y
bool move_Y(int d_start, int l_start_int, int d_end, int l_end_int, bool check=false) {
	string* current = &board[d_start][l_start_int];
	string* end = &board[d_end][l_end_int];

	int d_step = 1;
	int l_step = 1;

	if (player == 1 && (*end).length() > 0 && (*end)[1] == 'b') return false;
	if (player == -1 && (*end).length() > 0 && (*end)[1] == 'r') return false;

	if (abs(l_start_int - l_end_int) == abs(d_start - d_end)) {
		if (d_start > d_end) d_step = -1;
		if (l_start_int > l_end_int) l_step = -1;

		for (int i = d_start + d_step, j = l_start_int + l_step; i != d_end; i += d_step, j += l_step) {
			if (abs(d_start - d_end) == 1) break;
			if (board[i][j] != "") {
				return false;
			}
		}
		if (!check){
			*end = *current;
			*current = "";
		}
		return true;
	}
	return false;
}

//Q
bool move_Q(int d_start, int l_start_int, int d_end, int l_end_int) {
	if (!move_U(d_start, l_start_int, d_end, l_end_int)) {
		if (!move_Y(d_start, l_start_int, d_end, l_end_int)) return false;
	}
	return true;
}

//J
bool move_J(int d_start, int l_start_int, int d_end, int l_end_int, bool check=false) {
	string* current = &board[d_start][l_start_int];
	string* end = &board[d_end][l_end_int];
	bool is_true = false;
	bool flag = false;
	if (abs(d_start - d_end) == 1 && abs(l_start_int - l_end_int) == 2) {
		is_true = true;
	}
	if (abs(d_start - d_end) == 2 && abs(l_start_int - l_end_int) == 1) {
		is_true = true;
	}
	if (is_true) {
		if (*end == "") {
			flag = true;
		}
		else {
			if (player == 1 && (*end)[1] == 'r') {
				flag = true;
			}
			if (player == -1 && (*end)[1] == 'b') {
				flag = true;
			}
		}
	}
	if (flag && (!check)){
		*end = *current;
		*current = "";
	}
	if (flag) {
		return true;
	}
	return false;
}

//K
int move_K(int y_start, int x_start_int, int y_end, int x_end_int) {
	string* current = &board[y_start][x_start_int];
	string* end = &board[y_end][x_end_int];
	bool flag = false;
	
	char player_warning_check='0';
	int king_check_x = -1; //checking king with x position
	int king_check_y = -1; //checking king with y position
	
	if (abs(y_start - y_end) <= 1 && abs(x_start_int - x_end_int) <= 1) {
		if (*end == "") {
			flag = true;
		}
		else {
			if (player == 1 && (*end)[1] == 'r') {
				flag = true;
			}
			if (player == -1 && (*end)[1] == 'b') {
				flag = true;
			}
		}
	}
	if (flag){
		if (player == 1){
			king_b_x = x_end_int;
			king_b_y = y_end;
		}
		else{
			king_r_x = x_end_int;
			king_r_y = y_end;
		}
		*end = *current;
		*current = "";
	}
	return flag;
}



bool move_main(int x_start, int y_start, int x_end, int y_end) {
	
	int res=0;
	
	int l_start_int = x_start;
	int d_start = y_start;
	int l_end_int = x_end;
	int d_end = y_end;
	if (board[d_start][l_start_int] == "") return 0;
	if (player == 1 && board[d_start][l_start_int][1] == 'r') return false;
	if (player == -1 && board[d_start][l_start_int][1] == 'b') return false;
	if (l_start_int == l_end_int && d_start == d_end) {
		return false;
	}
	if (l_start_int < 0 || l_start_int > 7) {
		return false;
	}
	if (l_end_int < 0 || l_end_int > 7) {
		return false;
	}
	if (d_start < 0 || d_start > 7) {
		return false;
	}
	if (d_end < 0 || d_end > 7) {
		return false;
	}

	//i
	if (board[d_start][l_start_int][0] == 'i') {
		if (!move_i(d_start, l_start_int, d_end, l_end_int)) {
			return false;
		}
	}
	//U
	else if (board[d_start][l_start_int][0] == 'U') {
		if (!move_U(d_start, l_start_int, d_end, l_end_int)) {
			return false;
		}
	}
	//Y
	else if (board[d_start][l_start_int][0] == 'Y') {
		if (!move_Y(d_start, l_start_int, d_end, l_end_int)) {
			return false;
		}
	}
	//Q
	else if (board[d_start][l_start_int][0] == 'Q') {
		if (!move_Q(d_start, l_start_int, d_end, l_end_int)) {
			return false;
		}
	}
	//J
	else if (board[d_start][l_start_int][0] == 'J') {
		if (!move_J(d_start, l_start_int, d_end, l_end_int)) {
			return false;
		}
	}
	//K
	else if (board[d_start][l_start_int][0] == 'K') {
		if (!move_K(d_start, l_start_int, d_end, l_end_int)) {
			return false;
		}
	}
		

	//null
	else {
		return false;
	}
	
	
	return true;
	
}


void warning_check(){
	bool check = false;
	int king_check_x = -1;
	int king_check_y = -1;
	string* current = nullptr;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			
			current = &board[i][j];
			if (*current == "") continue;
			
			if ((*current)[1] == 'b'){
				king_check_x = king_r_x;
				king_check_y = king_r_y;
			}
			if ((*current)[1] == 'r'){
				king_check_x = king_b_x;
				king_check_y = king_b_y;
			}
			
			
			if ((*current)[0] == 'i'){
				if (move_i(i, j, king_check_y, king_check_x, true)){
					check = true;
				}
			}
			if ((*current)[0] == 'J'){
				if (move_J(i, j, king_check_y, king_check_x, true)){
					check = true;
				}
			}
			/*if ((*current)[0] == 'U'){
				if (move_U(i, j, king_check_y, king_check_x, true)){
					check = true;
				}
			}*/
			if ((*current)[0] == 'Y'){
				if (move_Y(i, j, king_check_y, king_check_x, true)){
					check = true;
				}
			}
			
			if (check){
				warning = (board[i][j][1] == 'b' ? -1 : 1);
				return;
			}
		}
	}
	warning = 0;
	return;
}


int main()
{
	set_board();
	bool flag = false;
	bool is_ok = true;
	
	cout << "wasd to move\nf to choose\nb to cancel choice\nh to surrender\n\nPress any key to continue...";
	_getch();
	
	while (true) {
		system("cls");
		cout << "Player " << (player == 1 ? "1:" : "2:") << endl;
		cout << endl;
		print_board();
		char move = '0';
		
		if (!game) break; //game end
		
		if (flag) {
			cout << "End pos > ";
			move = _getch();
			if (move == 'w' && checked_y_end > 0) checked_y_end--;
			if (move == 's' && checked_y_end < 7) checked_y_end++;
			if (move == 'a' && checked_x_end > 0) checked_x_end--;
			if (move == 'd' && checked_x_end < 7) checked_x_end++;
			if (move == 'f') {
				is_ok = move_main(checked_x, checked_y, checked_x_end, checked_y_end);
				checked_y = checked_y_end;
				checked_x = checked_x_end;
				checked_x_end = -1;
				checked_y_end = -1;
				if (is_ok) player = -player;
				warning_check();
				flag = false;
			}
			if (move == 'b'){
				checked_x_end = -1;
				checked_y_end = -1;
				flag = false;
			}
		}
		else {
			cout << "Start pos > ";
			move = _getch();
			if (move == 'w' && checked_y > 0) checked_y--;
			if (move == 's' && checked_y < 7) checked_y++;
			if (move == 'a' && checked_x > 0) checked_x--;
			if (move == 'd' && checked_x < 7) checked_x++;
			if (move == 'f') {
				checked_x_end = checked_x;
				checked_y_end = checked_y;
				flag = true;
			}
			if (move == 'h') game = false;
		}
	}
	cout << "\a\n\nPlayer " << (player == 1 ? "2:" : "1:") << " won!" << endl;
}
