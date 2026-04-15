#include <iostream>
#include <cstring>
#include <clocale>
using namespace std;
const int SIZE = 20;
enum style { metal, jazz, blues, techno, shansshon };
struct album {
    char name[25];        // название альбома
    char band[25];        // исполнитель
    style genre;          // стиль
    int year;             // год выпуска
    int time;             // длительность 
    int price;            // стоимость
};

//Датасет
album* init() {
    album* albums = new album[SIZE];
    albums[0] = { "Ride the Lighting","Metallica", metal, 1978, 40, 10 };
    albums[1] = { "Caphead OST", "Caphead", jazz, 2017, 50, 15 };
    albums[2] = { "Alan Wake 2 OST", "Asgard", blues, 2023, 60, 15 };
    albums[3] = { "Kill em all","Retallica", metal, 1976, 50, 10 };
    albums[4] = { "Master of Puppets","Eetallica", techno, 1981, 70, 10 };
    albums[5] = { "Frahk Sinatra the Best","Frank", techno, 1963, 90, 20 };
    albums[6] = { "Elvis Vol1","Elvis", blues, 1963, 120, 30 };
    albums[7] = { "The Silver Beatls","Beatles", blues, 1961, 40, 10 };
    albums[8] = { "Load","Netallica", techno, 1979, 45, 15 };
    albums[9] = { "jazz vol1", "Igor", jazz, 2017, 55, 15 };
    albums[10] = { "blues vol1", "Anton", blues, 2021, 62, 40 };
    albums[11] = { "Raining blood","Slayer", metal, 1975, 50, 100 };
    albums[12] = { "ReLoad","Atallica", metal, 2001, 80, 10 };
    albums[13] = { "Frahk Sinatra the Best2","Srank", jazz, 1965, 90, 30 };
    albums[14] = { "Elvis Vol2","Elvis", blues, 1966, 127, 30 };
    albums[15] = { "The Big Silver Beatls","Bitles", blues, 1962, 110, 2 };
    albums[16] = { "Pice sels","Megadeth", techno, 1973, 100, 15 };
    albums[17] = { "Master of Puppets","a", techno, 1981, 70, 10 };
    albums[18] = { "Frahk Sinatra the Best3","Jank", jazz, 1961, 100, 210 };
    albums[19] = { "Elvis Vol3","ZElvis", blues, 1951, 150, 150 };
    return albums;
}
//Функция для изменения альбома
void editAlbum(album* albums, int size) {
    setlocale(LC_ALL, "Russian");
    int num;
    cout << " Редактирование альбома " << endl;
    cout << "Введите номер альбома (от 1 до 20): ";
    cin >> num;
    if (num < 1 || num > 20) {
        cout << "Такого нет" << endl;
        return;
    }
    int index = num - 1;  
    cout << "Текущие данные:" << endl;
    cout << "1. Название: " << albums[index].name << endl;
    cout << "2. Исполнитель: " << albums[index].band << endl;
    cout << "3. Год выпуска: " << albums[index].year << endl;
    cout << "4. Длительность: " << albums[index].time << endl;
    cout << "5. Стоимость: " << albums[index].price << endl;
    int choice;
    cout << "Что меняем?: ";
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Новое название: ";
        cin >> albums[index].name;
        break;
    case 2:
        cout << "Новый исполнитель: ";
        cin >> albums[index].band;
        break;
    case 3:
        cout << "Новый год: ";
        cin >> albums[index].year;
        break;
    case 4:
        cout << "Новая длительность: ";
        cin >> albums[index].time;
        break;
    case 5:
        cout << "Новая стоимость: ";
        cin >> albums[index].price;
        break;
    default:
        cout << "такого нету" << endl;
        return;
    }
    cout << "Готово" << endl;
}
// Оберточная функция для вывода массива альбомов
void printAlbums(album* arr, int count, const char* title) {
    setlocale(LC_ALL, "Russian");
    cout <<  title   << endl;
    if (count == 0) {
        cout << "пусто" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << arr[i].band << " - " << arr[i].name;
        cout << " (" << arr[i].time << " мин, " << arr[i].price << "$)" << endl;
    }
}
// Функция для вывода жанра
void printGenre(style g) {
    if (g == metal) cout << "metal";
    else if (g == jazz) cout << "jazz";
    else if (g == blues) cout << "blues";
    else if (g == techno) cout << "techno";
    else cout << "shansshon";
}
//Пересобираем только с джазом и блюзом
int main() {
    setlocale(LC_ALL, "Russian"); 
    album* albums = init();
    album* jazzBluesAlbums = new album[SIZE];
    int j = 0;

    for (int i = 0; i < SIZE; i++) {
        if (albums[i].genre == jazz || albums[i].genre == blues) {
            jazzBluesAlbums[j] = albums[i];
            j++;
        }
    }

    // Сортируем по алфавиту 
    for (int i = 0; i < j - 1; i++) {
        for (int k = 0; k < j - i - 1; k++) {
            if (strcmp(jazzBluesAlbums[k].band, jazzBluesAlbums[k + 1].band) > 0) {
                album temp = jazzBluesAlbums[k];
                jazzBluesAlbums[k] = jazzBluesAlbums[k + 1];
                jazzBluesAlbums[k + 1] = temp;
            }
        }
    }

    // Вывод отсортированного массива с джазом и блюзом
    printAlbums(jazzBluesAlbums, j, "Джаз и блюз по алфавиту");
    
    // Вывод инфы по конкретному альбому
    int number;
    cout << "Введите номер альбома (1-20): ";
    cin >> number;
    if (number > 0 && number < 21) {
        cout << "Название альбома: " << albums[number - 1].name << endl;
        cout << "Стоимость: " << albums[number - 1].price << endl;
        cout << "Длительность в минутах: " << albums[number - 1].time << endl;
    }
    else {
        cout << "Альбома с таким номером нет" << endl;
    }
    // Собираем техно альбомы и сортируем по цене
    album* technoAlbums = new album[SIZE];
    int t = 0;
    for (int i = 0; i < SIZE; i++) {
        if (albums[i].genre == techno) {
            technoAlbums[t] = albums[i];
            t++;
        }
    }
    for (int i = 0; i < t - 1; i++) {
        for (int k = 0; k < t - i - 1; k++) {
            if (technoAlbums[k].price < technoAlbums[k + 1].price) {
                album temp = technoAlbums[k];
                technoAlbums[k] = technoAlbums[k + 1];
                technoAlbums[k + 1] = temp;
            }
        }
    }
    // Вывод 5 самых популярных техно-альбомов
    int count = (t < 5) ? t : 5;
    printAlbums(technoAlbums, count, "5 самых дорогих техно-альбомов");
    
    // Массив с альбомами более 40 минут и его вывод
    album* longAlbums = new album[SIZE];
    int l = 0;
    for (int i = 0; i < SIZE; i++) {
        if (albums[i].time > 40) {
            longAlbums[l] = albums[i];
            l++;
        }
    }
    printAlbums(longAlbums, l, "Альбомы длительностью более 40 минут");
    
    // Изменение альбома
    editAlbum(albums, SIZE);
    return 0;
}