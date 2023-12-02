// Stat defines
#define MAX_MINERS 10 // Max number of miners available at any given time on map

/* Bitconin miners */
#define MINER      "B"
#define MINER_CHANCE 15 // 1/15 chance of spawning

class Miner { 
    public: 
        Miner(char* c, char* name, int rarity, int rate);
        ~Miner();
        
        // Getters
        char* get_char();
        char* get_name();
        int get_rarity();
        int get_ncoin();
        int get_rate();
    private:
        char* c;
        char* name;
        int rarity;
        int ncoin; 
        int rate; 
};

Miner::Miner(char* c, char* name, int rarity, int rate) { 
    this->c = c;           // Symbol on map
    this->name = name;     // Name of printer
    this->rarity = rarity; // Chance of spawning
    this->ncoin = 0;       // Number of coin accumalated
    this->rate = rate;     // Rate at which coin is mined in seconds
}

Miner::~Miner() { 
    // Not implemented
}

// Getters 
char* Miner::get_char() { return this->c; }
char* Miner::get_name() { return this->name; }
int Miner::get_rarity() { return this->rarity; }
int Miner::get_ncoin()  { return this->ncoin; }
int Miner::get_rate()   { return this->rate; }
