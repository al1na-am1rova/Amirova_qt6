// #include "Amirova_Actor.h"
// #include "Amirova_Group.h"
// #include "utils.h"


// void menu() {
//     // cout << "����" << endl
//     // 	<< "1 - ������ ������ ������" << endl
//  //        << "2 - ������ ������ ������ ������" << endl
//     // 	<< "3 - ������� ���� �������" << endl
//     // 	<< "4 - �������� ������ �� ������� � ����" << endl
//     // 	<< "5 - ������� ������ �� ������� �� �����" << endl
//  //        << "6 - �������� ������" << endl
//  //        << "7 - �����" << endl;

//     cout << "menu" << endl
//          << "1 - create new actor" << endl
//          << "2 - create new theater actor" << endl
//          << "3 - show all actors" << endl
//          << "4 - save data to file" << endl
//          << "5 - load data from file" << endl
//          << "6 - clear all actors" << endl
//          << "7 - exit" << endl;
// }

// int main_func()
// {
//     setlocale(LC_ALL, "Russian");
//     SetConsoleCP(1251);
//     SetConsoleOutputCP(1251);

//     Amirova_Group group;

// 	while (true) {
// 		menu();
//         int command = get_correct_number(1, 7);
//         switch (command) {
//         case 1:
//             group.add_actor();
//             break;
//         case 2:
//             group.add_theater_actor();
//             break;
//         case 3:
//             group.show_all_actors();
//             break;
//         case 4:
//             group.save_to_file();
//             break;
//         case 5:
//             group.load_from_file();
//             break;
//         case 6:
//             group.clear_all();
//             break;
//         case 7:
//             return 0;
//         }
// 	}
// }
