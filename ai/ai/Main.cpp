//#include <SFML/Graphics.hpp>
//using namespace sf; //пространство имен sf блеать
//int main()
//{
//	Clock clock;//переменная времени
//	RenderWindow window(sf::VideoMode(640, 480), "GETTING STARTED");//создание окна
//	Image heroImg; //объект изображения
//	heroImg.loadFromFile("Images/purple-sprite.png");//загрузка из файла 
//
//	Texture heroTex;//Создание объекта текстуры
//	heroTex.loadFromImage(heroImg);//передаем объект изображения
//
//	Sprite heroSpr; //создание объекта спрайта
//	heroSpr.setTexture(heroTex);//передаем объект текстуры
//	heroSpr.setTextureRect(IntRect(0, 0, 16, 16));//нужное изображение персонажа
//	heroSpr.setPosition(200, 150);//начальные координаты появления спрайта
//
//	float time;
//
//	while (window.isOpen())
//	{
//		time = clock.getElapsedTime().asMicroseconds();
//		clock.restart();
//		time = time / 800;
//		printf("%f\n", time);
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Left))
//		{
//			heroSpr.setTextureRect(IntRect(17, 17, 16, 16));//повернуть перса по направлению движения
//			heroSpr.move(-0.1*time, 0);
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Right))
//		{
//			heroSpr.setTextureRect(IntRect(17, 0, 16, 16));//повернуть перса по направлению движения
//			heroSpr.move(0.1*time, 0);
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Up))
//		{
//			heroSpr.setTextureRect(IntRect(0, 17, 16, 16));//повернуть перса по направлению движения
//			heroSpr.move(0, -0.1*time);
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Down))
//		{
//			heroSpr.setTextureRect(IntRect(0, 0, 16, 16));//повернуть перса по направлению движения
//			heroSpr.move(0, 0.1*time);
//		}
//		window.clear();
//		window.draw(heroSpr);//выводим спрайт на экран
//		window.display();
//	}
//
//	return 0;
//}