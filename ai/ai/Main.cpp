//#include <SFML/Graphics.hpp>
//using namespace sf; //������������ ���� sf ������
//int main()
//{
//	Clock clock;//���������� �������
//	RenderWindow window(sf::VideoMode(640, 480), "GETTING STARTED");//�������� ����
//	Image heroImg; //������ �����������
//	heroImg.loadFromFile("Images/purple-sprite.png");//�������� �� ����� 
//
//	Texture heroTex;//�������� ������� ��������
//	heroTex.loadFromImage(heroImg);//�������� ������ �����������
//
//	Sprite heroSpr; //�������� ������� �������
//	heroSpr.setTexture(heroTex);//�������� ������ ��������
//	heroSpr.setTextureRect(IntRect(0, 0, 16, 16));//������ ����������� ���������
//	heroSpr.setPosition(200, 150);//��������� ���������� ��������� �������
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
//			heroSpr.setTextureRect(IntRect(17, 17, 16, 16));//��������� ����� �� ����������� ��������
//			heroSpr.move(-0.1*time, 0);
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Right))
//		{
//			heroSpr.setTextureRect(IntRect(17, 0, 16, 16));//��������� ����� �� ����������� ��������
//			heroSpr.move(0.1*time, 0);
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Up))
//		{
//			heroSpr.setTextureRect(IntRect(0, 17, 16, 16));//��������� ����� �� ����������� ��������
//			heroSpr.move(0, -0.1*time);
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Down))
//		{
//			heroSpr.setTextureRect(IntRect(0, 0, 16, 16));//��������� ����� �� ����������� ��������
//			heroSpr.move(0, 0.1*time);
//		}
//		window.clear();
//		window.draw(heroSpr);//������� ������ �� �����
//		window.display();
//	}
//
//	return 0;
//}