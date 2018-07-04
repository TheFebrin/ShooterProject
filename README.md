# ShooterProject
Project for object oriented programming

Krótki opis

Projekt, który przygotowaliśmy jest grą zręcznościową, jednoosobową i lokalną. Gra została zaprogramowana w języku C++. Dodatkowo użyliśmy zewnętrznej graficznej biblioteki SFML.

Rozgrywka

Podczas gry sterujemy naszą postacią na dwuwymiarowej mapie. (Gra jest w widoku „z góry”). Do poruszania się używamy przycisków AWSD oraz myszy. Położenie kursora na ekranie determinuje kierunek lotu pocisków, które możemy wystrzelić klikając lewy przycisk Myszy. Oprócz naszej postaci na ekranie znajdują się tzw. „wrogowie”, którzy poruszają się po mapie z prędkością podobną do prędkości gracza. Generowani są oni w losowych miejscach na mapie. Z dużej odległości nie widzą naszej postaci, ale poniżej pewnej zaczynają podążać w jej stronę. Gdy zbliżą się oni dostatcznie i dojdzie do kolizji – zostaną odebrane punkty życia naszej postaci. Gracz strzelając we wrogów może ich zlikwidować.

Biblioteka SFML

SFML to akronim od Simple Fast Multimedia Library. Jest to międzyplatformowa biblioteka, która dostarcza prosty interface do projektowania różnych aplikacji okienkowych. Została napisana w C++.  W projekcie używamy jej do utworzenia okna graficznego aplikacji i rysowania grafiki na ekranie w oparciu o zwracane przez odpowiedzialną za logikę część aplikacji wartości.

Wykorzystane wzorce projektowe

Cała aplikacja oparta jest na wzorcu obiektowym. Program składa się z modułów – klas, które są odpowiedzialne za poszczególne jego elementy. Osobną klasę ma gracz, wróg, pocisk i inne. Bardziej szczegółowo o klasach i zależnościach między nimi można przeczytać w rodziale: „Klasy  w projekcie” oraz „Diagramy UML”.

Klasy w projekcie

Animation

Bullet

Przechowuje pozycję i prędkość pocisku. 
Metody: 
Update() zmienia pozycję pocisku.
Metoda DrawBullet() renderuje pocisk na ekranie gry.
GetCollider() zwraca wymiary grafiki pocisku potrzebne do sprawdzania kolizji z innymi obiektami na mapie.
GetEnemyPosition() zwraca wymiary grafiki gracza potrzebne do sprawdzenia kolizji.

Collider

Obsługuje kolizje pomiędzy obiektami na mapie.

Metody:
CheckCollision() zwraca true jeśli obiekty nachodzą na siebie na mapie i false w przeciwnym wypadku.
Move() przemieszcza obiekt wstecz w przypadku wykrycia kolizji przez CheckCollision().

Enemy

Zawiera informacje o pozycji wroga na mapie, o tym czy jest żywy, o jego prędkości i o wymiarach tekstury.

Metody:
Update() aktualizuje pozycję wroga na mapie w zależności od wciśniętych przycisków.
DrawEnemy() renderuje teksturę wroga w oknie gry.
GetCollider() zwraca wymiary i pozycję tekstury, która potencjalnie może kolidować z innymi obiektami na mapie.

Game

Obsługuje cały przebieg gry. Wykonuje wszystkie zdarzenia podczas gry.

Metody:
RunGame() dopóki okno gry jest otwarte wywołuje  i wykonuje potrzebne eventy, aktualizuje pozycje wszystkich obiektów na mapie oraz ryzuje je wraz ze scenerią na ekranie.
IsRunning() funkcja boolowska, która sprawdza czy gra jest aktualnie uruchomiona.
ProcessEvents() nasłuchuje eventów wychodzących od użytkownika takich jak naciśnięcie przycisku lub zamknięcie okna gry.
HandlePlayerInput() decyduje, w którą stronę poruszyć gracza w zależności od wciśniętych przycisków na klawiaturze.
Render() renderuje gracza na ekranie oraz wyświetla okno gry.

GenerateRandomNumber

Generuje pseudolosową liczbę, na podstawie której zostanie utworzona „losowa” pozycja wroga.

Metody:
generateRandom() generuje liczbę pseudolosową.


Player

Podobnie jak wróg. Gracz ma swoją pozycję, prędkość i punkty życia.

Metody:
Update() aktualizuje pozycję gracza i animuje jego ruch.
DrawPlayer() renderuje teksturę gracza na mapie w oparciu o jego pozycję.


Scene Node







