# ShooterProject
Project for object oriented programming
<br>
<h3>Krótki opis</h3>
<br>
Projekt, który przygotowaliśmy jest grą zręcznościową, jednoosobową i lokalną. Gra została zaprogramowana w języku C++. Dodatkowo użyliśmy zewnętrznej graficznej biblioteki SFML.
<br>
<h3>Rozgrywka i działanie gry</h3>
<br>
Podczas gry sterujemy naszą postacią na dwuwymiarowej mapie. (Gra jest w widoku „z góry”). Do poruszania się używamy przycisków AWSD oraz spacji aby strzelać. Oprócz naszej postaci na ekranie znajdują się tzw. „wrogowie”, którzy poruszają się po mapie z prędkością podobną do prędkości gracza. Generowani są oni w losowych miejscach na mapie. Z dużej odległości nie widzą naszej postaci, ale poniżej pewnej zaczynają podążać w jej stronę. Gdy zbliżą się oni dostatcznie i dojdzie do kolizji – zostaną odebrane punkty życia naszej postaci. Gracz strzelając we wrogów może ich zlikwidować. Pojedyńczy strzał odbiera część życia wroga.
Gracz porusza sie na ograniczonej mapie, z której nie może się wydostać. Jego zadaniem jest przetrwać jak najdłużej. Okno gry można dowolnie resize'ować i nie wpłynie to na działanie gry. Domyślne okno ma rozdzielczość 1200x720. Limit fps to 120, a większość funkcji, ktore poruszają obiekty przyjmuje parametr deltaTime, który odpowiada za płynną synchronizację. Struktura gry opiera się o funkcje main, w ktorej jest otwarte okno. Dopóki to okno jest otwarte w pętli przechwytywane są wszystkie zdarzenia. Najważniejsze funkcje w pętli to generowanie wrogów i pocisków, update pozycji dla wszystkich obiektów, detekcja kolizji pomiędzy wszystkimi obiektami oraz wyświetlanie całości kontentu na ekran.
<br>
<h3>Biblioteka SFML</h3>
<br>
SFML to akronim od Simple Fast Multimedia Library. Jest to międzyplatformowa biblioteka, która dostarcza prosty interface do projektowania różnych aplikacji okienkowych. Została napisana w C++.  W projekcie używamy jej do utworzenia okna graficznego aplikacji i rysowania grafiki na ekranie w oparciu o zwracane przez odpowiedzialną za logikę część aplikacji wartości.
<br>
<h3>Wykorzystane wzorce projektowe</h3>
<br>
Cała aplikacja oparta jest na wzorcu obiektowym. Program składa się z modułów – klas, które są odpowiedzialne za poszczególne jego elementy. Osobną klasę ma gracz, wróg, pocisk i inne. Bardziej szczegółowo o klasach i zależnościach między nimi można przeczytać w rodziale: „Klasy  w projekcie” oraz „Diagramy UML”.
<br>
<h4>The Facade pattern</h4>
W naszym projekcie klasa Entity jest bazą dla m. in. klas Player, Bullet i Enemy. Pomaga to w lepszym zorganizowaniu projektu i zapobieka skomplikowanym powiązaniom.
<h4>Composite pattern</h4>
Jest to wzorzec, którego można by użyć w naszym projekcie i uprościć nieco struktuę. Metody LowerHealth i Destroy są wykorzystywane we wszystkich klasach odpowiadajacych za postacie w grze. Można by łączyć sprawdzanie stanu zdrowia obiektu z kolizją z pociskiem i nie używać do tego żadnej instrukcji warunkowej, a jedynie przekazać przez konstruktor do klasy implementującej metodę Update(). Wtedy w jednym momencie aktualizowana byłaby nie tylko pozycja, ale również punkty życia i nie trzeba byłoby tego specyfikować osobno.

<h4>Interfeace segregation pattern</h4>
W naszym projekcie powielone są wielokrotnie metody Update(), Draw() itp. Można by stworzyć interface'y, które niejako "posegregowałyby" klasy o podobnych metodach dzięki czemu uzyskalibyśmy większy porządek w projekcie.


<h3>Klasy w projekcie: </h3>
<h3>Animation</h3>
Klasa odpowiedzialna za animacje Gracza oraz wrogów. Animacja ma miejsce przez stałe zmienianie wyświetlanego obrazka w zależności w którą strone porusza się dany obiekt.

Ważniejsze metody:
<ul>
  <li>Update() zmienia aktualnie animowane pole tekstury gracza lub wroga</li>
</ul>
<br>
<h3>Bullet</h3>
Klasa przechowująca wszystkie parametry pocisku wystrzelonego przez gracza.

Ważniejsze metody:
<ul>
<li>Update() zmienia pozycję pocisku </li>
<li>DrawBullet() renderuje pocisk na ekranie gry</li>
<li>Destroy() daje programowi znać, że pocisk należy już usunąć </li>
</ul>
<br>
<h3>Collider</h3>
Obsługuje kolizje pomiędzy obiektami na mapie. Im cięższy obiekt, tym większy współczynnik tarcia, więc gracz kolidując
z takim obiektem może go przesuwać z różną szybkością i na odwrót. Gracz, przeciwnik, pocisk i każdy inny obiekt dla którego chcemy wykryc kolizję ma w swojej klasie swój Collider.

Ważniejsze metody:
<ul>
<li>CheckCollision() zwraca true jeśli obiekty nachodzą na siebie na mapie i false w przeciwnym wypadku (metoda AABB) </li>
<li>Move() przemieszcza obiekt wstecz w przypadku wykrycia kolizji przez CheckCollision()</li>
</ul>
<br>
<h3>Enemy</h3>
Zawiera informacje o pozycji wroga na mapie, o tym czy jest żywy, o jego prędkości, życiu, ataku, wymiarach itp.

Ważniejsze metody:
<ul>
<li>Update() aktualizuje pozycję wroga na mapie, jeżeli gracz jest daleko porusza się losowo, wpp goni gracza </li>
<li>DrawEnemy() renderuje teksturę wroga w oknie gry </li>
<li>GetCollider() zwraca wymiary i pozycję tekstury, która potencjalnie może kolidować z innymi obiektami na mapie</li>
<li>Destroy() zaznacza, że danego wroga trzeba usunąć, bo został zabity </li>
<li>LowerHealth() gdy gracz zaatakuje wroga obniża życie wroga </li>
</ul>
<br>
<h3>Player</h3>
Podobnie jak wróg. Gracz ma swoją pozycję, prędkość, obrażenia, życie itp.

Ważniejsze metody:
<ul>
<li>Update() aktualizuje pozycję gracza przechwytując wciśnięte klawicze i animuje jego ruch</li>
<li>DrawPlayer() renderuje teksturę gracza na mapie w oparciu o jego pozycję</li>
<li>LowerHealth() gdy wróg zaatakuje gracza, ten traci punkty zdrowia </li>
</ul>
<br>
<h3>TextDisplay</h3>
Klasa odpowiada za wyświetlanie tekstu na ekran np. punktów zdrowia, czy obrażeń.

Ważniejsze metody:
<ul>
<li>Update() zmiana pozycji tekstu </li>
<li>DrawText() renderuje tekst na ekran</li>
</ul>
<br>
<h3>Entity</h3>
Klasa zawierająca podstawowe rodzaje tekstur, takie jak RectangleShape, czy Sprite. Dziedziczy z niej Enemy, Bullet oraz TextDisplay.
<br>
<h3>HUD</h3>
Klasa wyświetlająca panel gry i informacje o graczu takie jak np. życie.
<br>
<h3>Platform</h3>
Klasa odpowiadająca za generowanie bloków, i innych elementów terenu utrudniających poruszanie. Wykrywalna jest kolizja gracza i takiego obiektu. Granice mapy są obiektami klasy Platform.

Ważniejsze metody:
<ul>
<li>GetCollider() pobiera collider obiektu </li>
<li>Draw() renderuje na ekran</li>
</ul>
<br>
