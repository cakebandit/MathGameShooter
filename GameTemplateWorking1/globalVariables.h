#pragma once
#include "SFMLHeader.h"
#include "mainship.h"
#include "mathShip.h"
#include "GameState.h"

using namespace sf;

class globalVariables {
public:
	void textinputMethod(Event& event, std::string& str, mainShip& mainShip, std::list<mathShip>& listMathShip, Text& enteredText, int& score) {
		if (event.type == Event::TextEntered) {
			if (event.text.unicode == '\b') {
				if (str.size() > 0) {
					str.erase(str.size() - 1, 1);
				}
			}


			if (event.text.unicode == '\r') {
				if (str.size() > 0) {
					mainShip.answer = std::stoi(str);
					str.erase(str.size() - str.size());
				}
				for (mathShip& ms : listMathShip) {
					if (ms.isAlive == true) {
						if (mainShip.position.y > ms.position.y - 20 && mainShip.position.y < ms.position.y + 20) {
							ms.answerquestion(mainShip.answer, score);
							if (ms.answer == mainShip.answer) {
								score += 1;
								ms.isAlive = false;
							}
						}
					}

				}
			}

			else if (str.size() < 5) {
				if (event.text.unicode < 58 && 47 < event.text.unicode) {
					str += static_cast<char>(event.text.unicode);
				}
			}
			enteredText.setString(str);
		}
	}


	void spawningMines(Time& time1, Clock& clock, std::list<mathShip>& listMathShip) {
		if ((rand() % 47 + 200) < time1.asSeconds()) {
			clock.restart();
			time1 = time1 - time1;

			for (int i = 0; i < 1; i++) {
				mathShip ms(rand() % 400 + 20);
				if (ms.isAlive == true) {
					listMathShip.push_front(ms);
				}
				
				i = 0;
			}
		}
	}

	void settingTextVarGame(Text& scorebox, Text& enteredText, Font& font) {
		scorebox.setCharacterSize(20);
		scorebox.setFont(font);
		scorebox.setPosition(30, 20);

		enteredText.setFont(font);
		enteredText.setCharacterSize(20);
	}

	void settingTextVarDeath(int currentscore, int highscoregame, Sprite yourdeadsprite, Text highscore, Font font) {

		if (currentscore > highscoregame) {
			highscoregame = currentscore;
		}
		yourdeadsprite.setScale(1.4, 1.45);
		yourdeadsprite.setPosition(-53, 90);

		highscore.setCharacterSize(20);
		highscore.setFont(font);
		highscore.setPosition(20, 440);

	}
};

