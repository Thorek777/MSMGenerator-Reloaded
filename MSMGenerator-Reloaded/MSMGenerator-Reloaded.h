#pragma once

#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

string sciezka1 = "Models/";
string sciezka2 = "SourceSkins/";
string sciezka3 = "TargetSkins/";
string sciezka4 = "Faces/";
string sciezka5;

vector<string> pliki1 = {};
vector<string> pliki2 = {};
vector<string> pliki3 = {};
vector<string> pliki4 = {};

int wybor;
int ile_wpisow_stworzyc;
int aktualna_liczba_wpisow;
int aktualna_liczba_index;
int model_twarzy;
int i;
int licznik_plikow1;
int licznik_plikow2;
int licznik_plikow3;
int licznik_plikow4;

bool rozpoczynanie_od_zera = false;

void sprawdzanie();
void generacja();
