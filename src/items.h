// Stat defines
#define MAX_MINERS 10 // Max number of miners available at any given time on map

/* Bitconin miners */
#define MINER      "B"
#define MINER_CHANCE 15 // 1/15 chance of spawning

class Miner { 
    public: 
        Miner(char* c, char* name, int rarity);
        ~Miner();
        
        // Getters
        char* get_char();
        char* get_name();
        int get_rarity();
        int get_ncoin();
    private:
        char* c;
        char* name;
        int rarity;
        int ncoin; 
};

Miner::Miner(char* c, char* name, int rarity) { 
    this->c = c;
    this->name = name;
    this->rarity = rarity;
    this->ncoin = 0;
}

Miner::~Miner() { 

}

// Getters 
char* Miner::get_char() { return this->c; }
char* Miner::get_name() { return this->name; }
int Miner::get_rarity() { return this->rarity; }
int Miner::get_ncoin() { return this->ncoin; }
