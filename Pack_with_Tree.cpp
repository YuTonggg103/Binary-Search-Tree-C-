#include"G21_TP068052_TP068224_TP069018_Pack_with_Tree.hpp"
int main() {
	StateBasedTree tree("Tree");
	tree.addNode("CX1234", 27022024, "Muhmad", "6015523639", "Jocelyn", "6013652710", 81100, "Johor Baharu", "Johor", "Malaysia", 1, 7);
	tree.addNode("CX1236", 14022024, "Lorna", "6012358649", "Nadia", "6017761169", 31600, "Gopeng", "Perak", "Malaysia", 2, 8);
	tree.addNode("CX1238", 6012024, "Yvonne", "6019819757", "Ivan", "6018853865", 89900, "Tenom", "Sabah", "Malaysia", 3, 9);
	tree.addNode("CX1235", 25012024, "Angela", "6012963568", "Angie", "6014761990", 81000, "Kulai", "Johor", "Malaysia", 4, 10);
	tree.addNode("CX1237", 25022024, "Darrell", "6017468790", "Lester", "6017229953", 31900, "Kampar", "Perak", "Malaysia", 5, 11);
	tree.addNode("CX1251", 14022024, "Fiony", "6017481440", "Alstre", "6016732350", 81400, "Senai", "Johor", "Malaysia", 6, 12);
	tree.addNode("CX1240", 15012024, "Lily", "6019128186", "Ali", "6018592613", 31650, "Ipoh", "Perak", "Malaysia", 7, 13);
	tree.addNode("CX1239", 18022024, "Melly", "6017620595", "Nichlos", "6019405219", 81000, "Kulai", "Johor", "Malaysia", 8, 14);
	tree.addNode("CX1242", 25012024, "Horward", "6018031155", "Nizam", "6017855415", 81700, "Johor Baharu", "Johor", "Malaysia", 9, 15);
	tree.addNode("CX1244", 1122024, "Mick", "6012528311", "Oscle", "6019725663", 89100, "Pitas", "Sabah", "Malaysia", 10, 16);
	tree.addNode("CX1241", 2022024, "Alice", "6016160146", "Kaley", "6015530926", 89907, "Tenom", "Sabah", "Malaysia", 11, 17);
	tree.addNode("CX1243", 13022024, "Joanne", "6013129059", "Joel", "6015675031", 81400, "Saleng", "Johor", "Malaysia", 12, 18);
	tree.addNode("CX1248", 7022024, "Sam", "6017854567", "Samuel", "6012466710", 81400, "Senai", "Johor", "Malaysia", 13, 19);
	tree.addNode("CX1246", 14022024, "Albert", "6016113650", "Darrick", "6016599676", 81000, "Kulai", "Johor", "Malaysia", 14, 20);
	tree.addNode("CX1245", 28012024, "Daisy", "6012561721", "Peter", "6019647403", 31650, "Ipoh", "Perak", "Malaysia", 15, 21);
	tree.addNode("CX1250", 20012024, "Umi", "6017435887", "Simon", "6017304382", 89050, "Pitas", "Sabah", "Malaysia", 16, 22);
	tree.addNode("CX1247", 16022024, "Zoe", "6016921382", "David", "6014372653", 80000, "Johor Baharu", "Johor", "Malaysia", 17, 23);
	tree.addNode("CX1249", 11012024, "Chloe", "6015054989", "Judas", "6014630148", 81800, "Johor Baharu", "Johor", "Malaysia", 18, 24);

	tree.inorderOutputByState(1);
	tree.askToDelete();
	cout << endl << string(230, '-') << endl;
	tree.inorderOutputByState(2);
	return 0;
}


