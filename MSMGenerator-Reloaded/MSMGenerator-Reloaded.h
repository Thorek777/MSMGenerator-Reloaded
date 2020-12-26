#pragma once

#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

string sciezka1 = "Models/", sciezka2 = "SourceSkins/", sciezka3 = "TargetSkins/", sciezka4 = "Faces/", sciezka5;
vector<string> pliki1 = {}, pliki2 = {}, pliki3 = {}, pliki4 = {};
int wybor, ile_wpisow_stworzyc, aktualna_liczba_wpisow, aktualna_liczba_index, model_twarzy, i, licznik_plikow1, licznik_plikow2, licznik_plikow3, licznik_plikow4;
bool rozpoczynanie_od_zera = false;
void sprawdzanie(), generacja();
