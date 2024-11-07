Cell cells[CELLCOUNT];
Player players[PLAYERCOUNT];
MysteryCell mysteryCell;

unsigned short int mysteryIndex;
unsigned short int mysteryRemaining = 4;
unsigned short int prevMysteryIndex = -1;
unsigned short int currentPiece = 0; // for blue player
unsigned short int prevRound; //for mystery effect
unsigned short int playerIndex; // currntly playing player


void playgroundSetup();
void playerSetup();
short int toss();
unsigned short int diceRolling(char*);
unsigned short int genarateMystery(unsigned short int);
unsigned short int getFirstPlayer(Player*);
void dispalySummery();
void displayComesStartingPoint(char*, unsigned short int, unsigned short int);
void displayMove(char*, unsigned short int, unsigned short int, unsigned short int,unsigned short int,short int);
bool comesToX(Player*, Piece*);
void resetPiece(Player*, Piece*);
bool movePiece(unsigned short int, Piece*, unsigned short int);
bool moveBlock(unsigned short int);
bool capture(unsigned short int, unsigned short int);
void redPlayer(unsigned short int);
void yellowPlayer(unsigned short int);
void bluePlayer(unsigned short int);
void greenPlayer(unsigned short int);
void playingPlayer(unsigned short int, unsigned short int);
bool calMystery(unsigned short int, Piece*, unsigned short int);
void resetMystery();
void game();


void resetMystery(Piece *piece){
    
    piece->isMystery = false;
    piece->mysteryId = -1;
    piece->mysteryWeight = 0;
    piece->mysteryRound = 0;


}


bool calMystery(unsigned short int playerIndex, Piece* piece, unsigned short int steps){

    if(piece->isMystery)return false;//if piece alred in mystrey cell then skip

    Player *player = &players[playerIndex];
    unsigned short int nextIndex = piece->position + piece->wice*steps;
    unsigned short int mysteryId;
    unsigned short int teleportIndex;

    if(nextIndex == mysteryIndex && !piece->isMystery){

        piece->isMystery= true;
        printf("%s player lands on a mystery cell and is teleported to ",player->name);

        switch (mysteryCell.mysteryId){

            case 1: //bhawana
                piece->position = 9;
                piece->mysteryId = 1;
                piece->mysteryWeight = mysteryCell.mysteryWeight;// set mystrey dice value effect
                
                printf("Bhawana.\n");
                printf("%s piece %c%d teleported to Bhawana.\n",player->name, player->name[0],piece->name);
                
                if((int)piece->mysteryWeight==2){
                    printf("%s piece %c%d feels energized, and movement speed doubles.\n",player->name, player->name[0],piece->name);
                }

                if((int)piece->mysteryWeight==0){
                    printf("%s piece %c%d feels sick, and movement speed halves.\n",player->name, player->name[0],piece->name);
                }

                if(piece->wice > 0){

                    switch (playerIndex){
                        case 0:
                            piece->positionCounter = POSITION_COUNTER_BHAWANA_YELLOW;
                            break;
                        case 1:
                            piece->positionCounter = POSITION_COUNTER_BHAWANA_BLUE;
                            break;
                        case 2:
                            piece->positionCounter = POSITION_COUNTER_BHAWANA_RED;
                            break;
                        case 3:
                            piece->positionCounter = POSITION_COUNTER_BHAWANA_GREEN;
                            break;
                    }
                }

                else{

                    switch (playerIndex){

                        case 0:
                            piece->positionCounter = (52 - POSITION_COUNTER_BHAWANA_YELLOW);
                            break;
                        case 1:
                            piece->positionCounter = (52 - POSITION_COUNTER_BHAWANA_BLUE);
                            break;
                        case 2:
                            piece->positionCounter = (52 - POSITION_COUNTER_BHAWANA_RED);
                            break;
                        case 3:
                            piece->positionCounter = (52 - POSITION_COUNTER_BHAWANA_GREEN);
                            break;
                    }
                }

                break;

            
            case 3:// pitakotuwa

                piece->position = 46;
                piece->mysteryId = 3;

                printf("Pita-Kotuwa.\n");
                printf("%s piece %c%d teleported to Pita-Kotuwa.\n",player->name, player->name[0],piece->name);
                
                if(piece->wice>0){
                    printf("The %s piece %c%d, which was moving clockwise, has changed to moving coun-terclockwise.\n",player->name, player->name[0],piece->name);
                }

                else{
                    printf("The %s piece %c%d is moving in a counterclockwise direction. Teleporting to Kotuwa from Pita-Kotuwa.\n",player->name, player->name[0],piece->name);
                }

                if(piece->wice>0){

                    piece->wice = -1; // chanege direction clockwice to counter-cockwice
                    switch (playerIndex){

                        case 0:
                            piece->positionCounter = POSITION_COUNTER_PITAKOTUWA_YELLOW;
                            break;
                        case 1:
                            piece->positionCounter = POSITION_COUNTER_PITAKOTUWA_BLUE;
                            break;
                        case 2:
                            piece->positionCounter = POSITION_COUNTER_PITAKOTUWA_RED;
                            break;
                        case 3:
                            piece->positionCounter = POSITION_COUNTER_PITAKOTUWA_GREEN;
                            break;
                    }
                    break;
                }
            
            case 2: //kotuwa

                piece->position = 27;
                piece->mysteryId = 2;
                piece->mysteryWeight = 0;

                printf("Kotuwa.\n");
                printf("%s piece %c%d teleported to Kotuwa.\n",player->name, player->name[0],piece->name);
                printf("%s piece %c%d attends briefing and cannot move for four rounds.\n",player->name, player->name[0],piece->name);

                if(piece->wice > 0){

                    switch (playerIndex){
                        case 0:
                            piece->positionCounter = POSITION_COUNTER_KOTUWA_YELLOW;
                            break;
                        case 1:
                            piece->positionCounter = POSITION_COUNTER_KOTUWA_BLUE;
                            break;
                        case 2:
                            piece->positionCounter = POSITION_COUNTER_KOTUWA_RED;
                            break;
                        case 3:
                            piece->positionCounter = POSITION_COUNTER_KOTUWA_GREEN;
                            break;
                    }
                }

                else{

                   switch (playerIndex){

                        case 0:
                            piece->positionCounter = 52 - POSITION_COUNTER_KOTUWA_YELLOW;
                            break;
                        case 1:
                            piece->positionCounter = 52 -  POSITION_COUNTER_KOTUWA_BLUE;
                            break;
                        case 2:
                            piece->positionCounter = 52 - POSITION_COUNTER_KOTUWA_RED;
                            break;
                        case 3:
                            piece->positionCounter = 52 - POSITION_COUNTER_KOTUWA_GREEN;
                            break;
                    } 
                }
                break;
            
            case 4: // base

                // piece->position = 0;
                piece->mysteryId = 4;
                piece->mysteryWeight = 0;
                resetMystery(piece);
                resetPiece(&players[playerIndex],piece);
                
                printf("Base.\n");
                printf("%s piece %c%d teleported to Base.\n",player->name, player->name[0],piece->name);
                
                break;
            
            case 5: //x of the piece colour

                piece->mysteryId = 5;
                piece->positionCounter = 0;
                piece->position = players[playerIndex].startingPoint;
                
                printf("X of the piece colour.\n");
                printf("%s piece %c%d teleported to X.\n",player->name, player->name[0],piece->name);
                
                break;

            case 6://Approach of the piece colour

                piece->mysteryId = 6;
                piece->position = players[playerIndex].approchPoint;
                piece->positionCounter = piece->approchLength;
                
                printf("Approach of the piece.\n");
                printf("%s piece %c%d teleported to Approach.\n",player->name, player->name[0],piece->name);

                break;
        }
        return true;
    }
    return false;
}


unsigned short int genarateMystery(unsigned short int round){
    
    if(prevRound==round)return mysteryIndex; // when player got six then true this contidion
    prevRound = round;

    unsigned short int mystery = rand()%52;
    if(cells[mystery].isEmpty && (prevMysteryIndex == -1 || prevMysteryIndex != mystery )){
        
        mysteryCell.cell = mystery;
        mysteryCell.mysteryId = rand()%6 +1;//1-bhawana, 2-kotuwa, 3-pitakotuwa, 4-base, 5-x of the piece, 6-approch of the colour

        // Bhawana
        if(mysteryCell.mysteryId == 1){

            switch(rand()%2){
                case 0 :
                    mysteryCell.mysteryWeight = 2;//double the dice value
                    break;
                case 1 :
                    mysteryCell.mysteryWeight = (float)1/2;//half the dice value
                    break;
            }
        }

        // kotuwa
        if(mysteryCell.mysteryId == 2){

            mysteryCell.mysteryWeight = 0; //lock piece position
        }

        printf("A mystery cell has spawned in location %d and will be at this location for the next four rounds.\n",mystery);
        return mystery;
    }

    else{
         // if mystrey cell generated on piece's location the change mystrey location
       return genarateMystery(round);
    }
}


void playgroundSetup(){

    for(int i=0;i<52;i++){
        Cell *cell= &cells[i];
        cell->id=i;
        cell->blockSize= 0;
        cell->blockId = -1;
        cell->isEmpty=true;
        cell->isBlock=false;
    }
}


//set defaults to playerd
void playerSetup(Player players[PLAYERCOUNT]){

   //player names setup
   strcpy(players[0].name,"Yellow");
   strcpy(players[1].name,"Blue");
   strcpy(players[2].name,"Red");
   strcpy(players[3].name,"Green");

   unsigned short int startIndex=2;

    for(int i=0; i<4; i++){
        Player *player = &players[i];
        player->onplaying=0;
        player->startingPoint=startIndex;
        player->approchPoint=(startIndex+50)%52;
        player->homePieces=0;
        player->isWin=false;

        for(int j=0;j<4;j++){
            Piece *piece =&player->pieces[j];
            piece->name = j+1;
            piece->position=0;
            piece->wice=1;
            //piece.stringPosition=0;
            //piece.approshCell=players[i].approchPoint;
            piece->isPlaying=false;
            piece->isStright=false;
            piece->isHome=false;
            piece->canIntoHome=false;
            piece->mysteryId = -1;
            piece->isMystery = false;
        }

        startIndex= (startIndex+13)%52;
    }
    //The red player has four (04) pieces named R1, R2, R3, and R4.
    for(int i=0; i<4; i++){
        Player *player = &players[i];
        printf("The %s player has four (04) pieces named",player->name);
        for(int j=0;j<4;j++){
            printf(" %c%d",player->name[0],j+1);
            if(j!=3)printf(",");
        }
        printf(".\n");
        
    }
    printf("\n");
    
    
}


short int toss(){
    bool toss= rand() % 2;
    if(toss==0){return -1;};
    return toss;
}


unsigned short int diceRolling(char name[]){
    int val = (1 + (rand() % 6));
	printf("\n%s Rolled %d\n",name,val);
	return val;
};


unsigned short int getFirstplayer(Player players[4]){
    short int curruntPlayer=0,previous=0;
    for(int i=0; i<4;i++){
        unsigned short int value =diceRolling(players[i].name);
        if (previous<value){ //previous player dice value less than new then 
            curruntPlayer = i;
            previous= value;
        }
    }
    printf("\n%s player has the highest roll and will begin the game.\n\n",players[curruntPlayer].name); 
    printf("The order of a single round is ");

    //printing order of the players
    for(int i=0;i<4;i++){
        printf("%s ",players[(curruntPlayer+i)%4].name);
        if(i==2) printf("and ");
    }
    printf("\b.\n\n");
    return curruntPlayer;
}


//display fuctions
void displaySummery(){
    // player iterate
    for(int i=0; i<4; i++){
        printf("\n%s player now has %d/4 on pieces on the board and %d/4 pieces on the base.\n",players[i].name, players[i].onplaying, 4- players[i].onplaying-players[i].homePieces);
        printf("============================\n");
        printf("Location of pieces %s\n", players[i].name);
        printf("============================\n");
        
        for(int j=0; j<4; j++){
            Piece piece = players[i].pieces[j];
            printf("Piece %c%d --> ",players[i].name[0],piece.name);
            
            if(piece.isHome){ printf("Home.\n"); continue;}
            if(piece.isStright){ printf("Home Stright. \n"); continue;}
            if(piece.isPlaying){ printf("L%d.\n",piece.position); continue;}
            
            printf("Base.\n"); 
        }
        printf("\n"); 
    }
    printf("The mystery cell is at %d and will be at that location for the next %d values.\n\n", mysteryIndex, mysteryRemaining );
    // printf("\n");
}


void displayComesStartingPoint(char player[8],unsigned short int pieceName,unsigned short int onplaying){
    printf("%s player moves piece %c%d to starting point.\n",player,player[0],pieceName);
    printf("%s player now has %d/4 on pieces on the board and %d/4 pieces on the base.\n",player,onplaying,4-onplaying);
}


void displayMove(char player[8], unsigned short int pieceName, unsigned short int Startposition, unsigned short int Endposition, unsigned short int steps, short int wice){
    char direction [20];
    (wice==1)? strcpy(direction,"clockwise") : strcpy(direction,"counter-clockwise");
    printf("%s moves piece %d from location %d to %d by %d units in %s direction.\n",player,pieceName,Startposition,Endposition,steps,direction);
}


//piece comes to starting cell
bool comessToX(Player *player,Piece* piece){
    Cell *startingCell = &cells[player->startingPoint]; 
    if(!piece->isPlaying && !piece->isHome && startingCell->isEmpty){
        player->onplaying++;
        piece->isPlaying=true;
        startingCell->isEmpty=false;
        piece->position=player->startingPoint;
        piece->positionCounter=0;
        displayComesStartingPoint(player->name,piece->name,player->onplaying);
        
        piece->wice=toss();// calculate piece direction
        
        if(piece->wice>0)piece->approchLength=50;
        
        else piece->approchLength=54;
        
        return true;
    }
    return false;
}


//reset piece value as defaults
void resetPiece(Player *player,Piece *piece){
    if(player->isWin || player->onplaying == 0 || piece->isHome || !piece->isPlaying) return;
    
    resetMystery(piece);
    
    piece->position =0;
    piece->wice =1;
    piece->blockId=0;
    piece->isPlaying=false;
    piece->canIntoHome =false;
    piece->positionCounter=0;
    piece->mysteryId = 0;
    piece->mysteryWeight = -1;
    piece->isMystery =false; 
    player->onplaying--;


}


bool movePiece(unsigned short int playerIndex,Piece *piece,unsigned short int steps){

    Player *player = &players[playerIndex];

    if(player->isWin) return true; //player has already won

    if(piece->isHome || !piece-> isPlaying) return false; //piece has aready home or base

    unsigned short int startPosition = piece->position;

    Cell *currentCell = &cells[piece->position];

    // piece in stright 
    if(piece->isStright){
        unsigned short int homeLen = 5 - piece->strightPosition;

        if(homeLen>=steps){
            piece->strightPosition += steps;
            printf("%s moves piece %d from location %d to %d by %d units in home stright. \n",player->name,piece->name,piece->strightPosition-steps,piece->strightPosition, steps);
            return true; 

        }
        if(piece->strightPosition >= 5){
            piece->isHome = true;
            player->homePieces++;
            player->onplaying--;
            printf("%s moves piece %d comes to Home !\n",player->name,piece->name); 

            if(player->homePieces == 4){

                printf("%s player wins!!!\n",player->name);
                exit(0);  
            }

            return true;
        }
        return false; //no enough steps to move
    }

    // mystery case
    if(mysteryIndex != -1){
         if(calMystery(playerIndex,piece,steps))return true;
    }

    if(piece->isMystery){
        
        piece->mysteryRound++;

        if (piece->mysteryRound >=4)resetMystery(piece);  // rest effect of mystrycell 

        switch (piece->mysteryId){

        case 1: //bhawana
            
            steps = steps * piece->mysteryWeight;
            break;

        case 2: //kotuwa
            
            if(piece->prevSteps == steps){
                piece->consecutiveStepCounter++;
                if(piece->consecutiveStepCounter == 3){
                    resetPiece(player, piece);
                    printf("%s piece %c%d is movement-restricted and has rolled three consecutively. Tele-porting piece %c%d to base.\n",player->name, player->name[0],piece->name, player->name[0],piece->name);
                    return true;
                }
            return true;
            }
            steps = steps * piece->mysteryWeight;
            break;

        case 3: //pitakotuwa
            
            break;

        case 4: //base
            
            break;

        case 5: //x of the piece colour
            
            break;

        case 6: //approch of the piece
            
            break;
        }
    }
    
    

    //approch to home stright
    if((piece->positionCounter + steps >= piece->approchLength) && !piece->isStright){
        short int approchLen;
        
       approchLen = piece->approchLength - piece->positionCounter;
         
        Cell *currentCell = &cells[piece->position];
        for(int i =0; i<approchLen; i++){
            unsigned short int nextPosition = (piece->position+ piece->wice+52)%52;
            Cell *nextCell = &cells[nextPosition];
            currentCell->isEmpty = true;
            currentCell=nextCell;
            piece->position=(piece->position+piece->wice+52)%52;
            piece->positionCounter++;
            steps--;
        }
            
        if(piece->canIntoHome){
            piece->isStright=true;
            
            if(steps > 0){
                piece->strightPosition += steps - 1;
                printf("%s's  piece %d entered to the Home striaght.\n",player->name,piece->name);
                printf("%s moves piece %d from location %d to %d by %d units in Home striaght.\n",player->name,piece->name,0,piece->strightPosition,steps);
                
            }
        }
        else{
            if(piece->wice>0)piece->positionCounter=-2; //reset the position counter
            else piece->positionCounter=2; //reset the position counter
            
            
        }
        return true;  
         
    }
    

    //block create
    // if(!cells[(piece->position + piece->wice*steps + 52)%52].isEmpty){
    //     unsigned short int nextPosition = (piece->position+ piece->wice*steps+52)%52;
    //     Cell *nextCell = &cells[nextPosition];
    //     if(nextCell->blockId==currentCell->blockId){
    //         currentCell->isEmpty=true;
    //         nextCell->isEmpty =false;
    //         piece->position = nextPosition;
    //         nextCell->blockSize++;
    //         nextCell->isBlock=true;
    //         return true;
            

    //     }
                
    // }
    // Cell *currentCell = &cells[piece->position];


    // normal movement 
    for(int i =0; i<steps; i++){
        unsigned short int nextPosition = (piece->position+ piece->wice+52)%52;
        Cell *nextCell = &cells[nextPosition];

        if(nextCell->isEmpty || !nextCell->isBlock){
            currentCell->isEmpty = true;
            nextCell->isEmpty = false;
            currentCell=nextCell;
            currentCell->blockId=playerIndex;
            piece->position=(piece->position + piece->wice +52)%52;
            piece->positionCounter++;
        }
        else break; //there is a block
                
    }
    displayMove(player->name,piece->name,startPosition,piece->position,steps,piece->wice); 

    if(playerIndex==2)return true; // this line for red player
    
    return true;
}


bool moveBlock(unsigned short int cellId){

    Cell *cell = &cells[cellId];
    if(!cell->isBlock) return false;

    return true;
}


//Normal capture function
bool capture(unsigned short int playerIndex, unsigned short int steps){

    Player *player = &players[playerIndex];

    for(int p=0; p<4; p++){

       Piece *piece = &player->pieces[p];

       if(!piece->isPlaying||piece->isHome || piece->isStright)continue; // if piece in on base or home or home stright, skip the piece  
       
       if(piece->canIntoHome && (playerIndex == 0 || playerIndex == 3))continue; //this line for yellow player and green
       
       unsigned short int nextPosition = (piece->wice*steps + piece->position + 52)%52;
        
        for(int i=0; i<4 ;i++){
            
            if(i == playerIndex)continue; //skip the same player

            Player *tempPlayer = &players[i]; //opponont Player

                for(int j=0;j<4;j++){
                    
                    Piece *tempPiece =&tempPlayer->pieces[j];
                    
                    if(!tempPiece->isPlaying|| tempPiece->isHome||tempPiece->isStright)continue; // if player in on base skipp the piece

                    if(nextPosition == tempPiece->position){

                        resetPiece(tempPlayer,tempPiece);

                        piece->canIntoHome = true;
                        cells[piece->position].isEmpty=true;
                        piece->position =nextPosition;
                        cells[piece->position].isEmpty=false;

                        printf("%s piece %d lands on square %d, captures %s piece %d, and returns it to the base.\n",player->name,piece->name,piece->position,tempPlayer->name,tempPiece->name);
                        printf("%s player now has %d/4 on pieces on the board and %d/4 pieces on the base.\n",tempPlayer->name,tempPlayer->onplaying, 4- tempPlayer->onplaying-tempPlayer->homePieces);
                        
                        playerIndex--; // bonus roll for capture
                        
                        return true;
                    }

                }
        }
    }
    return false;
}


//red palyer behevious
void redPlayer(unsigned short int diceValue){

    Player *player  = &players[2];
    unsigned short int staringCellIndex = player->startingPoint;

    Piece *capturedPiece = NULL; // who is captured piece
    Piece *piece = NULL; // currently checking piece of red player
    Piece *capturingPiece = NULL; // who is make capture
    Piece *tempPiece = NULL; 
    Player *tempPlayer = NULL;
    Player *capturedPlayer = NULL; //who is captuered player
    short int approchLen, prevApprochLen = 52;   
    short int nextPosition;

    if (player->isWin) return; //check player status(win or not)
    
    // *****check if any piece in the board
    if (player->onplaying == 0 && diceValue ==6){ 

        for(int i=0; i<4; i++){

            Piece *piece = &player->pieces[i];
            if(comessToX(player, piece))break;
        }

        return;
    }



    // --------------------- capture opponent piece ------------------------------

    
    // check each piece
    for(int i=0; i<4; i++){

        piece = &player->pieces[i];

        if(!piece->isPlaying || piece->isHome || piece->isStright)continue;

        nextPosition = (piece->position + piece->wice*diceValue + 52)%52;

        // check each player
        for(int j=0; j<4; j++){
            tempPlayer = &players[j];
            if(tempPlayer == player || tempPlayer->isWin ||(!tempPlayer->isWin && tempPlayer->onplaying==0))continue;// skip same player and won players
            
            // chech each pieces
            for(int k=0; k<4; k++){
                tempPiece = &tempPlayer->pieces[k];
                
                if(tempPiece->isHome || !tempPiece-> isPlaying ||tempPiece->isStright || nextPosition != tempPiece->position) continue; //skip each piece at home or base
                // get the lenth to approch cell
                if(tempPiece->wice>0){

                    approchLen = (52 - tempPiece->position + tempPlayer->approchPoint)%52; 
                }
                else{

                    approchLen = (52 - tempPlayer->approchPoint + tempPiece->position)%52;
                }
                if(nextPosition == tempPiece->position && approchLen < prevApprochLen ){ 

                    capturedPiece = tempPiece;
                    capturingPiece = piece;
                    prevApprochLen = approchLen;

                }

            }
            
            
        }
    }

    //to search Captureedplayer
    for(unsigned short int i = 0; i < 4 && capturedPiece !=NULL; i++){

        for(unsigned short int j = 0; j<4; j++){

            if(&players[i].pieces[j] == capturedPiece){

                capturedPlayer = &players[i];
            }
        }
    }


    if(capturedPiece!=NULL && tempPiece->isPlaying){

        resetPiece(capturedPlayer,capturedPiece);
        capturingPiece->canIntoHome =true;
        cells[capturingPiece->position].isEmpty = true ;// reset current cell
        capturingPiece->position = nextPosition;
        cells[capturingPiece->position].isEmpty = false ;
        printf("%s piece %c%d lands on square L%d, captures %s piece %c%d, and returns it to the base.\n",player->name,player->name[0],capturingPiece->name,capturingPiece->position,capturedPlayer->name,capturedPlayer->name[0],capturedPiece->name);
        printf("%s player now has %d/4 on pieces on the board and %d/4 pieces on the base.\n",capturedPlayer->name,capturedPlayer->onplaying,4-capturedPlayer->onplaying-capturedPlayer->homePieces);
        
        return;
    }


    if (diceValue == 6){ 
        for(int i=0; i<4; i++){

            Piece *piece = &player->pieces[i];
            if(comessToX(player, piece))break;
        }
        return;
    }

    // normal movement
    for(int i=0; i<PIECECOUNT; i++){

        if(movePiece(2,&player->pieces[i],diceValue))return;
    }

    printf("No any valid movements \n");

    
}


//Yellow[0] player behevious
void yellowPlayer(unsigned short int diceValue){
    Player *player  = &players[0];
    unsigned short  int approhLenght;
    short int minApprochLength = -1; //to store lenght to approch Cell 
    

    if (player->isWin) return; //check player status(win or not)

    //piece comes to board
    if(diceValue == 6 ){
            Cell *startingCell = &cells[player->startingPoint];
            for(unsigned short int i =0; i<4; i++){
                Piece *piece = &player->pieces[i];
                if (comessToX(player,  piece)) return;
            }
        }
    //capture a piece
    if(capture(0,diceValue))return;
    
    // move Piece
    Piece *toBeMovePiece  = NULL;
    for(int i=0; i<4; i++){
        Piece *piece = &player->pieces[i];
        if(!piece->isPlaying || piece->isHome)continue; //skip piece which is in base
        approhLenght = (player->approchPoint - piece->position +52)%52;

        if(minApprochLength == -1){
            minApprochLength = approhLenght; // first time
            // toBeMovePiece = piece;    
        }
        if(minApprochLength >= approhLenght && piece->canIntoHome){
            toBeMovePiece = piece;
        }

    }
    
    if(toBeMovePiece == NULL){
        for(int i=0; i<4; i++){
            Piece *piece = &player->pieces[i];
            if(!piece->isPlaying || piece->isHome)continue; //skip piece which is in base
            approhLenght = (player->approchPoint - piece->position +52)%52;

            if(minApprochLength == -1){
                minApprochLength = approhLenght; // first time
                // toBeMovePiece = piece;    
            }
            if(minApprochLength >= approhLenght){
                toBeMovePiece = piece;
            } 
        }
    }
    
    if(toBeMovePiece != NULL){
        if(movePiece(0,toBeMovePiece,diceValue))return;
    }
     
    return;
}


void bluePlayer(unsigned short int diceValue){

    Player *player  = &players[1];

    if(player->isWin) return; //check player status(win or not)

    currentPiece = ((currentPiece + 1) % 4); //cyclic manner of pieces
    

    // piece Comes to board
    if (diceValue == 6){

        Cell *startingCell = &cells[player->startingPoint];
        for(unsigned short int i = 0; i<4; i++){

            Piece *piece = &player->pieces[i];

            currentPiece = ((currentPiece) % 4) + 1;

            if(piece->isHome) continue; //skip piece that is already in home

            if(comessToX(player,piece))return;
        }

    }
    
    if(capture(1,diceValue))return;

    // movement of piece
    Piece *closetPieceToMystry = NULL, *longestPieceToMystry = NULL;
    unsigned short int mysteryLenght, prevMysteryLenght = 52, prevLenght = 0;

    for(unsigned short int i = 0; i < 4; i++){

        Piece *piece =&player->pieces[currentPiece];

        currentPiece = ((currentPiece + 1)%4);

        if(!piece->isPlaying || piece->isHome) continue; // skip piece that already won or still in base

        //check lenght to mystery call
        if(piece->wice < 0){

            mysteryLenght = (52 + piece->position - mysteryIndex) % 52;// if piece is counter-clockwice    
        }
        
        else{

            mysteryLenght = (52 - piece->position + mysteryIndex) % 52; // if piece is clockwice
        }

        //if its couter-clockwice, select piece what closest to mystery call
        if(mysteryLenght<=prevMysteryLenght && piece->wice < 0){ 
            closetPieceToMystry = piece;
            prevMysteryLenght = mysteryLenght;
        }

        // if piece is clockwice, select piece what longest to mystery call
        if(mysteryLenght >= prevLenght && piece->wice > 0){ 

            longestPieceToMystry = piece;
            prevLenght = mysteryLenght;
        }


    }

    if(closetPieceToMystry !=NULL){

        if(movePiece(1,closetPieceToMystry, diceValue))return;
    }

    if(longestPieceToMystry !=NULL){

        if(movePiece(1,longestPieceToMystry, diceValue))return;

    }

    // normal movement
    for(unsigned short int i = 0; i < 4; i++){
        
        Piece *piece = &player->pieces[currentPiece];

        currentPiece = (currentPiece + 1) % 4 ;

        if(!piece->isPlaying || piece->isHome) continue; // skip piece that already won or still in base
        
        if(movePiece(1,piece,diceValue))return;


    }

    printf("No any valid movements \n"); 
    return;

}


void greenPlayer(unsigned short int diceValue){    

    Player *player  = &players[3];
    unsigned short  int approhLenght;   // lenght to approch Cell 
    short int minApprochLength = -1;    // min lenght to approch Cell 
    Piece *toBeMovePiece  = NULL;       // what piece move in the board
    

    if (player->isWin) return; //check player status(win or not)

    //piece comes to board
    if(diceValue == 6 ){

        Cell *startingCell = &cells[player->startingPoint];

        for(unsigned short int i =0; i < PLAYERCOUNT; i++){

            Piece *piece = &player->pieces[i];

            if (comessToX(player,  piece)) return;
        }
    }

    //capture a piece
    if(capture(3,diceValue))return;
    
    // calculate what piece has min lenth to approch
    for(int i=0; i < PLAYERCOUNT; i++){

        Piece *piece = &player->pieces[i];
        
        if(!piece->isPlaying || piece->isHome)continue; //skip piece which is in base

        approhLenght = (player->approchPoint - piece->position +52) % 52; // calculate the approach lenght 

        if(minApprochLength == -1){

            minApprochLength = approhLenght; // first time
  
        }
        if(minApprochLength >= approhLenght && piece->canIntoHome){ 

            toBeMovePiece = piece;
        }

    }
    
    if(toBeMovePiece == NULL){

        for(int i=0; i < PLAYERCOUNT; i++){

            Piece *piece = &player->pieces[i];

            if(!piece->isPlaying || piece->isHome)continue; //skip piece which is in base

            approhLenght = (player->approchPoint - piece->position +52) % 52;

            if(minApprochLength == -1){
                minApprochLength = approhLenght; // first time

            }

            if(minApprochLength >= approhLenght){
                toBeMovePiece = piece;
            } 
        }
    }

    // move selected piece
    if(toBeMovePiece != NULL){

        if(movePiece(3,toBeMovePiece,diceValue))return;
    }

    printf("No any valid movements \n");
    return;
}

// select who is play now
void playingPlayer(unsigned short int playerIndex, unsigned short int diceValue){

    switch (playerIndex){

        case 0:
            yellowPlayer(diceValue);
            break;

        case 1:
            bluePlayer(diceValue);
            break;

        case 2:
            redPlayer(diceValue);
            break;

        case 3:
            greenPlayer(diceValue);
            break;

    }
}


void game(){

    playgroundSetup();

    playerSetup(players);

    unsigned short int  round, sixCount =0, numberOfWinners=0;

    playerIndex = getFirstplayer(players); // get who is play first

    do{ 
        Player currentPlayer = players[playerIndex];
        
        //generate the mystery cell
        if(round> 2 && round%16==0){
            mysteryIndex = genarateMystery(round);
            mysteryRemaining = 4;
        }

        if(!currentPlayer.isWin){
            
            unsigned short int diceValue = diceRolling(currentPlayer.name);
            
            // select who is playing next
            playingPlayer(playerIndex, diceValue);

            // Winning condition
            if(currentPlayer.homePieces == 4){

                currentPlayer.isWin=true;
                numberOfWinners++;

                if(numberOfWinners==1){

                    printf("%s player wins!!!\n",currentPlayer.name);
                    break;  // this will stop after a fist player win
                }

                //if want to contineue game until all players win need to remove above break
                else{
                    
                    printf("%s player end game.\n",currentPlayer.name);
                }
            }

            // if player rolls 6 then give a anther chance 
            if(diceValue == 6 && sixCount<2){
                sixCount++;
                continue;
            } 
		
        }	
	printf("%d", round);

        playerIndex = (playerIndex+1)%4;
        sixCount = 0 ;
        round++;

        // print summery after a round completed
        if(round%4==0){

            if(mysteryRemaining < 0 || mysteryRemaining > 4)mysteryRemaining=0; // 0 < mysteryRemaining < 4 
            
            displaySummery();  

            mysteryRemaining --;
        }
        // sleep(1);

    }while(numberOfWinners<4);
  
    
}
