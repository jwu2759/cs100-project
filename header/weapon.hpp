#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

class Weapon{
	protected:
		int attack;
		std::string phrase;
	public:
		
		Weapon(int atk, std::string phr){
			attack = atk;
			phrase = phr;
		}
		~Weapon();
		
		int getAttack(){return attack;}
		std::string getPhrase(){return phrase;}
};

class baseSword : public Weapon{
	protected: 
		attack = 20;
                phrase = "WHACKED ";	
	public:
		baseSword();
		~baseSword();		

};

class baseSpear : public Weapon{

        protected:
                attack = 15;
                phrase = "SHWOOOOMED ";

        public:
                baseSpear();
                ~baseSpear();

};

class baseAxe : public Weapon{
        private:
                attack = 10;
                phrase = "BONKED ";

        public:
                baseAxe();
                ~baseAxe();

};
#endif
