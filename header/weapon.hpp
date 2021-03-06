#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

class Weapon{
	protected:
		int attack;
		std::string phrase;
	public:
		
		Weapon(){}
		~Weapon();
		
		virtual int getAttack() = 0;
		virtual std::string getPhrase() = 0;

};

class baseSword : public Weapon{
	protected: 
		attack = 20;
                phrase = "WHACKED ";	
	public:
		baseSword();
		~baseSword();		
		virtual int getAttack(){
			return attack;
		}
                virtual std::string getPhrase(){
			return phrase;
		}
		virtual void setAttack(int num){

		}
                virtual void setPhrase(std::string phr) = 0;
};

class baseSpear : public Weapon{

        protected:
                attack = 15;
                phrase = "SHWOOOOMED ";

        public:
                baseSpear();
                ~baseSpear();
		virtual int getAttack(){
                        return attack;
                }
                virtual std::string getPhrase(){
                        return phrase;
                }
};

class baseAxe : public Weapon{
        private:
                attack = 10;
                phrase = "BONKED ";

        public:
                baseAxe();
                ~baseAxe();
		virtual int getAttack(){
                        return attack;
                }
                virtual std::string getPhrase(){
                        return phrase;
                }
};
#endif
