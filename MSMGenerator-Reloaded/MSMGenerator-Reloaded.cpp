#include "MSMGenerator-Reloaded.h"

int main() {
	setlocale(LC_CTYPE, "Polish");
	while (wybor != 1 && wybor != 2) {
		system("cls");
		cout << "------------------------------------ \n";
		cout << "- MSMGenerator By Thorek & Yellow. - \n";
		cout << "------------------------------------ \n \n";
		cout << "Wybierz jedną z poniższych opcji: \n \n";
		cout << "------------------------------------------------ \n";
		cout << "- 1. Tworzenie wpisów dla zbroi lub kostiumów. - \n";
		cout << "- 2. Tworzenie wpisów dla fryzur.              - \n";
		cout << "------------------------------------------------ \n\n";
		cin >> wybor;
	}
	cout << "\nIle wpisów chcesz stworzyć?: "; cin >> ile_wpisow_stworzyc;
	cout << "Ile ich aktualnie posiadasz?: "; cin >> aktualna_liczba_wpisow;
	cout << "Wprowadź swój największy Shape/HairIndex: "; cin >> aktualna_liczba_index;
	if (wybor == 1) { cout << "Dodać specjalną linijkę dla modelu twarzy? (0 - Nie, 1 - Tak): "; cin >> model_twarzy; }
	sprawdzanie();
}

void sprawdzanie() {
	system("cls");
	if (!filesystem::exists(sciezka1)) { cout << "Folder: \"Models\" nie istnieje! \n \n"; system("pause"); exit(0); }
	if (!filesystem::exists(sciezka2)) { cout << "Folder: \"SourceSkins\" nie istnieje! \n \n"; system("pause"); exit(0); }
	if (!filesystem::exists(sciezka3)) { cout << "Folder: \"TargetSkins\" nie istnieje! \n \n"; system("pause"); exit(0); }
	if (model_twarzy == 1 && !filesystem::exists(sciezka4)) { cout << "Folder: \"Faces\" nie istnieje! \n \n"; system("pause"); exit(0); }
	else {
		for (const auto& entry : filesystem::directory_iterator(sciezka1)) {
			sciezka5 = entry.path().string();
			sciezka5.erase(0, 7);
			pliki1.emplace_back(sciezka5);
			licznik_plikow1 += 1;
		}
		for (const auto& entry : filesystem::directory_iterator(sciezka2)) {
			sciezka5 = entry.path().string();
			sciezka5.erase(0, 12);
			pliki2.emplace_back(sciezka5);
			licznik_plikow2 += 1;
		}
		for (const auto& entry : filesystem::directory_iterator(sciezka3)) {
			sciezka5 = entry.path().string();
			sciezka5.erase(0, 12);
			pliki3.emplace_back(sciezka5);
			licznik_plikow3 += 1;
		}
		if (model_twarzy == 1) {
			for (const auto& entry : filesystem::directory_iterator(sciezka4)) {
				sciezka5 = entry.path().string();
				sciezka5.erase(0, 6);
				pliki4.emplace_back(sciezka5);
				licznik_plikow4 += 1;
			}
		}
		if (licznik_plikow1 < 1) { cout << "Folder: \"Models\" jest pusty. \n \n"; system("pause"); exit(0); }
		if (licznik_plikow2 < 1) { cout << "Folder: \"SourceSkins\" jest pusty. \n \n"; system("pause"); exit(0); }
		if (licznik_plikow3 < 1) { cout << "Folder: \"TargetSkins\" jest pusty. \n \n"; system("pause"); exit(0); }
		if (model_twarzy == 1 && licznik_plikow4 < 1) { cout << "Folder: \"Faces\" jest pusty. \n \n"; system("pause"); exit(0); }
		generacja();
	}
}

void generacja() {
	ofstream zapis("MSMGenerator.TXT");
	if (zapis.is_open()) {
		if (aktualna_liczba_wpisow > 0) {
			i = 1;
			rozpoczynanie_od_zera = true;
		}
		for (; i <= ile_wpisow_stworzyc; i++) {
			if (wybor == 1) {
				if (aktualna_liczba_wpisow + i < 10)
					zapis << "Group ShapeData0" << aktualna_liczba_wpisow + i;
				else
					zapis << "Group ShapeData" << aktualna_liczba_wpisow + i;
			}
			else if (wybor == 2) {
				if (aktualna_liczba_wpisow + i < 10)
					zapis << "\nGroup HairData0" << aktualna_liczba_wpisow + i;
				else
					zapis << "\nGroup HairData" << aktualna_liczba_wpisow + i;
			}

			zapis << "\n{";

			if (wybor == 1) zapis << "\n\tShapeIndex			" << aktualna_liczba_index + i;
			else if (wybor == 2) zapis << "\n\tHairIndex			" << aktualna_liczba_index + i;

			if (i < pliki1.size() && !rozpoczynanie_od_zera)
				zapis << "\n\tModel				" << "\"" << pliki1[i] << "\"";
			else if (i < pliki1.size() + 1 && rozpoczynanie_od_zera)
				zapis << "\n\tModel				" << "\"" << pliki1[i - 1] << "\"";
			else
				zapis << "\n\tModel				" << "\"" << pliki1[0] << "\"";

			if (i < pliki2.size() && !rozpoczynanie_od_zera)
				zapis << "\n\tSourceSkin			" << "\"" << pliki2[i] << "\"";
			else if (i < pliki2.size() + 1 && rozpoczynanie_od_zera)
				zapis << "\n\tSourceSkin			" << "\"" << pliki2[i - 1] << "\"";
			else
				zapis << "\n\tSourceSkin			" << "\"" << pliki2[0] << "\"";

			if (i < pliki3.size() && !rozpoczynanie_od_zera)
				zapis << "\n\tTargetSkin			" << "\"" << pliki3[i] << "\"";
			else if (i < pliki3.size() + 1 && rozpoczynanie_od_zera)
				zapis << "\n\tTargetSkin			" << "\"" << pliki3[i - 1] << "\"";
			else
				zapis << "\n\tTargetSkin			" << "\"" << pliki3[0] << "\"";

			if (model_twarzy == 1 && wybor == 1) zapis << "\n\tHead				" << "\"" << pliki4[0] << "\"";

			zapis << "\n}\n";
		}
		zapis.close();
	}
}
