#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <iostream> 
#include <vector> 

class MenuItem { 
public: 
    virtual void draw(sf::RenderWindow& window, bool isSelected) const = 0; 
    virtual void select() = 0; 
    virtual ~MenuItem() {} 
}; 
 
class TextMenuItem : public MenuItem { 
private: 
    sf::Text text; 
    sf::Color defaultColor; 
    sf::Color selectedColor; 
 
public: 
    TextMenuItem(const std::string& content, const sf::Font& font, unsigned int characterSize, const sf::Vector2f& position) 
        : text(content, font, characterSize) { 
        text.setPosition(position); 
        defaultColor = sf::Color::Black; 
        selectedColor = sf::Color::Red; 
        text.setFillColor(defaultColor); 
    } 
 
    void draw(sf::RenderWindow& window, bool isSelected) const override { 
        sf::Text drawText = text; 
        if (isSelected) { 
            drawText.setFillColor(selectedColor); 
        } 
        else { 
            drawText.setFillColor(defaultColor); 
        } 
        window.draw(drawText); 
    } 
 
    void select() override { 
        std::cout << "Selected: " << text.getString().toAnsiString() << std::endl; 
    } 
}; 

class GameMenuItem : public MenuItem { 
private: 
    sf::Text text; 
    sf::Color defaultColor; 
    sf::Color selectedColor; 
 
public: 
    GameMenuItem(const std::string& content, const sf::Font& font, unsigned int characterSize, const sf::Vector2f& position) 
        : text(content, font, characterSize) { 
        text.setPosition(position); 
        defaultColor = sf::Color::Black; 
        selectedColor = sf::Color::Green; 
        text.setFillColor(defaultColor); 
    } 
 
    void draw(sf::RenderWindow& window, bool isSelected) const override { 
        sf::Text drawText = text; 
        if (isSelected) { 
            drawText.setFillColor(selectedColor); 
        } 
        else { 
            drawText.setFillColor(defaultColor); 
        } 
        window.draw(drawText); 
    } 
 
    void select() override { 
        std::cout << "Selected: " << text.getString().toAnsiString() << std::endl; 
    } 
}; 
 
class SettingsMenuItem : public MenuItem { 
private: 
    sf::Text text; 
    sf::Color defaultColor; 
    sf::Color selectedColor; 
 
public: 
    SettingsMenuItem(const std::string& content, const sf::Font& font, unsigned int characterSize, const sf::Vector2f& position) 
        : text(content, font, characterSize) { 
        text.setPosition(position); 
        defaultColor = sf::Color::Black; 
        selectedColor = sf::Color::Red; 
        text.setFillColor(defaultColor); 
    } 
 
    void draw(sf::RenderWindow& window, bool isSelected) const override { 
        sf::Text drawText = text; 
        if (isSelected) { 
            drawText.setFillColor(selectedColor); 
        } 
        else { 
            drawText.setFillColor(defaultColor); 
        } 
        window.draw(drawText); 
    } 
 
    void select() override { 
        std::cout << "Selected Setting: " << text.getString().toAnsiString() << std::endl; 
    } 
}; 

class ThemeMenuItem : public MenuItem {
private:
    sf::Text text;    
    sf::Color defaultColor;
    sf::Color selectedColor;    
    bool isLightTheme;
public:
    ThemeMenuItem(const sf::Font& font, unsigned int characterSize, const sf::Vector2f& position):isLightTheme(true), defaultColor(sf::Color::Black), selectedColor(sf::Color::Red) {
        text.setFont(font);        
        text.setCharacterSize(characterSize);
        text.setPosition(position);        
        updateText();
    }
    void draw(sf::RenderWindow& window, bool isSelected) const override {        
        sf::Text drawText = text;
        if (isSelected) {            
            drawText.setFillColor(selectedColor);
        } else {            
            drawText.setFillColor(defaultColor);
        }        
        window.draw(drawText);
    }
    void select() override {        
        isLightTheme = !isLightTheme;
        updateText();        
        std::cout << "Selected Theme: " << (isLightTheme ? "Light" : "Dark") << std::endl;
    }
private:    
        void updateText() {
            sf::String themeText = "Theme: ";        
            themeText += (isLightTheme ? "Light" : "Dark");
            text.setString(themeText);    
        }
};

class SoundMenuItem : public MenuItem {private:
    sf::Text text;    
    sf::Color defaultColor;
    sf::Color selectedColor;    
    bool isLightTheme;
    bool isSoundOn;
    sf::Music music;
public:
    SoundMenuItem(const sf::Font& font, unsigned int characterSize, const sf::Vector2f& position):isLightTheme(true), defaultColor(sf::Color::Black), selectedColor(sf::Color::Red) {
        text.setFont(font);        
        text.setCharacterSize(characterSize);
        text.setPosition(position);        
        updateText();
        // if(!music.openFromFile("sound.mp3")){
        //     std::cerr<<"Failed to load sound"<<std::endl;
        // }
    }
    void draw(sf::RenderWindow& window, bool isSelected) const override {        
        sf::Text drawText = text;
        if (isSelected) {            
            drawText.setFillColor(selectedColor);
        } else {            
            drawText.setFillColor(defaultColor);
        }        
        window.draw(drawText);
    }
    void select() override {        
        isLightTheme = !isLightTheme;
        updateText();        
        std::cout << "Selected Sound: " << (isLightTheme ? "ON" : "OFF") << std::endl;
        // if(isSoundOn){
        //     music.play();
        // }
        // else{
        //     music.stop();
        // }
    }
private:    
        void updateText() {
            sf::String themeText = "Sound: ";        
            themeText += (isLightTheme ? "ON" : "OFF");
            text.setString(themeText);    
        }
};

class CreditsMenuItem : public MenuItem { 
private: 
    sf::Text text; 
    sf::Color defaultColor; 
    sf::Color selectedColor; 
 
public: 
    CreditsMenuItem(const std::string& content, const sf::Font& font, unsigned int characterSize, const sf::Vector2f& position) 
        : text(content, font, characterSize) { 
        text.setPosition(position); 
        defaultColor = sf::Color::Black;
        text.setFillColor(defaultColor); 
    } 
 
    void draw(sf::RenderWindow& window, bool isSelected) const override { 
        sf::Text drawText = text; 
        if (isSelected) { 
            drawText.setFillColor(selectedColor); 
        } else { 
            drawText.setFillColor(defaultColor); 
        } 
        window.draw(drawText); 
    } 
 
    void select() override { 
        std::cout << "Game created by: Gorodilov Pavel student of group IV-222" << std::endl; 
    } 
};
 
class Menu { 
private: 
    enum State{GAME,MAIN,SETTINGS,CREDITS};
    enum BgState{MAIN_BG, DARK_BG};
    std::vector<std::unique_ptr<MenuItem>> items; 
    std::vector<std::unique_ptr<MenuItem>> originalItems;
    sf::Texture backgroundTexture; 
    sf::Sprite backgroundSprite; 
    sf::Font font;
    State currentState = MAIN;
    BgState currentBg = MAIN_BG;
 
public: 
    Menu(const sf::Texture& backgroundTexture) : backgroundTexture(backgroundTexture) { 
        backgroundSprite.setTexture(backgroundTexture); 
        originalItems.push_back(std::make_unique<TextMenuItem>("Start Game", font, 50, sf::Vector2f(550, 280))); 
        originalItems.push_back(std::make_unique<TextMenuItem>("Options", font, 50, sf::Vector2f(590, 350)));
        originalItems.push_back(std::make_unique<TextMenuItem>("Credits", font, 50, sf::Vector2f(590, 430))); 
        originalItems.push_back(std::make_unique<TextMenuItem>("Exit", font, 50, sf::Vector2f(620, 510))); 
        if (!font.loadFromFile("arial.ttf")) { 
            std::cerr << "Failed to load font" << std::endl; 
        } 
    } 
 
    void addItem(std::unique_ptr<MenuItem> item) { 
        items.push_back(std::move(item)); 
    }
    void draw(sf::RenderWindow& window) const{ 
        window.draw(backgroundSprite); 
 
        for (size_t i = 0; i < items.size(); ++i) { 
            bool isSelected = (i == currentIndex); 
            items[i]->draw(window, isSelected); 
        } 
    } 
 
    void handleInput(sf::Event& event, sf::RenderWindow& window) { 
        if (event.type == sf::Event::KeyPressed) { 
            if (event.key.code == sf::Keyboard::Down) { 
                if(currentIndex > 2){
                    currentIndex = 0;
                }
                else if (currentIndex > 1 && currentState == SETTINGS){
                    currentIndex = 0;
                }
                else if (currentIndex == 1 && currentState == CREDITS){
                    currentIndex = 1;
                }
                else if (currentIndex == 0 && currentState == GAME){
                    currentIndex = 0;
                }
                else{
                    currentIndex = currentIndex + 1; 
                }
            } 
            else if (event.key.code == sf::Keyboard::Up) { 
                if(currentIndex == 0){
                    currentIndex = 3;
                    if (currentState == SETTINGS){
                        currentIndex = 2;
                    }
                    if (currentState == GAME){
                        currentIndex = 0;
                    }

                }
                else if (currentIndex == 1 && currentState == CREDITS){
                        currentIndex = 1;
                    }
                else{
                    currentIndex = currentIndex - 1; 
                }
            }
            else if (event.key.code == sf::Keyboard::Enter) { 
                items[currentIndex]->select(); 
                if(currentState == MAIN && currentIndex == 0){
                    if(!backgroundTexture.loadFromFile("game_image.jpeg")){
                        std::cerr<<"Failed to load new bg"<<std::endl;
                    }
                    backgroundSprite.setTexture(backgroundTexture);
                    originalItems = std::move(items); 
                    items.clear();
                    items.push_back(std::make_unique<GameMenuItem>("Back", font, 50, sf::Vector2f(50, 820))); 
                    currentState = GAME;
                    currentIndex = 0;
                }
                else if (currentIndex == 0 && currentState == GAME) { 
                    if(!backgroundTexture.loadFromFile("bg.jpeg")){
                        std::cerr<<"Failed to load bg"<<std::endl;
                    }
                    backgroundSprite.setTexture(backgroundTexture);
                    items = std::move(originalItems); 
                    currentState = MAIN;
                    currentIndex = 0;
                }
                else if (currentState == MAIN && currentIndex == 1) {
                    originalItems = std::move(items); 
                    items.clear();
                    items.push_back(std::make_unique<SoundMenuItem>(font, 50, sf::Vector2f(555, 360))); 
                    items.push_back(std::make_unique<ThemeMenuItem>(font, 50, sf::Vector2f(540, 420)));
                    items.push_back(std::make_unique<TextMenuItem>("Back", font, 50, sf::Vector2f(620, 480))); 
                    currentState = SETTINGS;
                    currentIndex = 0;
                }
                else if (currentIndex == 1 && currentState == SETTINGS && currentBg == MAIN_BG) { 
                    if(!backgroundTexture.loadFromFile("bg2.jpeg")){
                        std::cerr<<"Failed to load bg"<<std::endl;
                    }
                    backgroundSprite.setTexture(backgroundTexture);
                    currentBg = DARK_BG;
                    currentIndex = 1;
                }
                else if (currentIndex == 1 && currentState == SETTINGS && currentBg == DARK_BG) { 
                    if(!backgroundTexture.loadFromFile("bg.jpeg")){
                        std::cerr<<"Failed to load bg"<<std::endl;
                    }
                    backgroundSprite.setTexture(backgroundTexture);
                    currentBg = MAIN_BG;
                    currentIndex = 1; 
                }
                else if (currentIndex == 2 && currentState == SETTINGS) { 
                    items = std::move(originalItems); 
                    currentState = MAIN;
                    currentIndex = 0;
                }
                else if (currentState == MAIN && currentIndex == 2) {
                    originalItems = std::move(items); 
                    items.clear();
                    items.push_back(std::make_unique<CreditsMenuItem>("Game created by: Gorodilov Pavel student of group IV-222", font, 40, sf::Vector2f(150, 400))); 
                    items.push_back(std::make_unique<TextMenuItem>("Back", font, 50, sf::Vector2f(600, 480)));
                    currentState = CREDITS;
                    currentIndex = 1;
                }
                else if (currentIndex == 1 && currentState == CREDITS) { 
                    items = std::move(originalItems); 
                    currentState = MAIN;
                    currentIndex = 0;
                }
                else if (currentState == MAIN && currentIndex == 3) { 
                    window.close();
                }
            }
        }
    } 
 
private: 
    size_t currentIndex = 0; 
}; 