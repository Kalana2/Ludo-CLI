#ifndef TYPES_H  
#define TYPES_H 

#pragma pack(1)

#define PLAYERCOUNT 4
#define CELLCOUNT 52
#define PIECECOUNT 4

// mystrey cells(clockwice)
#define POSITION_COUNTER_BHAWANA_YELLOW 7
#define POSITION_COUNTER_BHAWANA_BLUE 46
#define POSITION_COUNTER_BHAWANA_RED 33
#define POSITION_COUNTER_BHAWANA_GREEN 20

#define POSITION_COUNTER_KOTUWA_YELLOW 25
#define POSITION_COUNTER_KOTUWA_BLUE 12
#define POSITION_COUNTER_KOTUWA_RED 51
#define POSITION_COUNTER_KOTUWA_GREEN 38

#define POSITION_COUNTER_PITAKOTUWA_YELLOW 44
#define POSITION_COUNTER_PITAKOTUWA_BLUE 31
#define POSITION_COUNTER_PITAKOTUWA_RED 18
#define POSITION_COUNTER_PITAKOTUWA_GREEN 5






typedef struct {
    unsigned short int name; //p1, p2, p3, p4
    unsigned short int position;
    short int positionCounter; //-2 add some times
    short int wice;
    unsigned short int approchLength;
    unsigned short int strightPosition;
    unsigned short int prevSteps; //for mystrey cell effect of kotuwa
    unsigned short int consecutiveStepCounter;//for mystrey cell effect of kotuwa
    unsigned short int blockId; //   
    short int mysteryId;//0-bhawana, 1-kotuwa, 2-pitaKotuwa, 3-base, 4-X of the piece Colour, 5-approch of the piece colour     
    float mysteryWeight; //only for bhawana and kotuwa
    unsigned short int mysteryRound;
    bool isMystery;
    bool isPlaying;
    bool isStright;
    bool isHome;
    bool canIntoHome; 
    
}Piece; 

typedef struct{
    char name[8];
    unsigned short int startingPoint;
    unsigned short int onplaying;
    unsigned short int approchPoint;
    unsigned short int homePieces;
    bool isWin; 
    Piece pieces[PIECECOUNT];

}Player;


typedef struct{
    unsigned short int id; 
    unsigned short int blockSize;  //number of block in cell
    short int blockId ;  // non -1, yellow 0, blue 1,red 2, green 3
    bool isEmpty; //piece is empty 1
    bool isBlock;   

}Cell;

typedef struct{
    unsigned short int cell; //store location 
    short int mysteryId;  //1-bhawana, 2-kotuwa, 3-pitakotuwa, 4-base, 5-x of the piece, 6-approch of the colour
    float mysteryWeight;
    
}MysteryCell;


#endif
