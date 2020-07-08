class Pole:public sf::Sprite{
        public:
            std::string name;
            int owner;  //0-puste           2-gracz 2(patrzy z dolu)       1- gracz 1 (patrzy z gory)
            int typK;
};
