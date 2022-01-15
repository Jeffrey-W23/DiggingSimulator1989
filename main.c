//--------------------------------------------------------------------------------------
// Purpose: The main script, used as a base for running the applcation.
//
// Author: Thomas Wiltshire
//--------------------------------------------------------------------------------------

// includes, using, etc
#include <stdio.h>
#include <gb/gb.h>
#include <gb/font.h>

// includes for the splash screen
#include "Sprite-Sheets/SplashTiles.c"
#include "Tile-Maps/SplashMap.c"

// Includes for the background layer
#include "Sprite-Sheets/BackgroundTiles.c"
#include "Tile-Maps/StartScreen.c"
#include "Tile-Maps/Background.c"

// includes for the window layer
#include "Dialog.c"

// includes for the sprite layer
#include "Player.c"
#include "Sprite-Sheets/Sprites.c"

// PUBLIC VARIABLES //
//--------------------------------------------------------------------------------------
// new Player object for storing the player postion, width, height, sprite ids
Player m_oPlayer;

// new unsiged int 8 array for the x and y positions of the background
UINT8 m_nBackgroundPos[2];

// new unsigned int 8 for the index on when to display text on the window layer
UINT8 m_nDialogIndex;

// new unsigned int 8 for keeping track of background fading stages. 
UINT8 m_nFadeIndex;
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
// SetDialog: Set a new dialog map for the window layer, Also sets the width, height 
// and x and y position.
// 
// Params:
//      cpDialog: Pointer to the dialog object to draw on window layer
//      nW: The width of the dialog object
//      nH: The hight of the dialog object
//      nX: The x position in the window layer
//      nY: The y poistion in the window layer
//--------------------------------------------------------------------------------------
void SetDialog(char* cpDialog, UINT8 nW, UINT8 nH, UINT8 nX, UINT8 nY)
{
    // Set the data for the window layer and move it into place
    set_win_tiles(0, 0, nW, nH, cpDialog);
    move_win(nX, nY);
}

//--------------------------------------------------------------------------------------
// MovePlayerCharacter: Move the player object, this is done by getting all the tiles
// used to represent the player sprite and moving them all together as one.
// 
// Params:
//      psPlayer: Pointer to the player object to move.
//      nX: The x position to set the player object.
//      nY: The y position to set the player object.
//--------------------------------------------------------------------------------------
void MovePlayerCharacter(Player* psPlayer, UINT8 nX, UINT8 nY)
{
    // Move sprite 0, top left tile
    move_sprite(psPlayer->ubSpriteIDs[0], nX, nY);

    // Move sprite 1, top right tile
    move_sprite(psPlayer->ubSpriteIDs[1], nX + 8, nY);

    // Move sprite 2, bottom left tile
    move_sprite(psPlayer->ubSpriteIDs[2], nX, nY + 8);
    
    // Move sprite 3, bottom right tile
    move_sprite(psPlayer->ubSpriteIDs[3], nX + 8, nY + 8);

    // Move sprite 4, bottom right tile
    move_sprite(psPlayer->ubSpriteIDs[4], nX, nY + 16);

    // Move sprite 5, bottom right tile
    move_sprite(psPlayer->ubSpriteIDs[5], nX + 8, nY + 16);
}

//--------------------------------------------------------------------------------------
// SetupPlayer: Initalize the player object, setting values and organizing sprites for use
//--------------------------------------------------------------------------------------
void SetupPlayer()
{
    // Set inital player values
    m_oPlayer.nX = 80;
    m_oPlayer.nY = 35;
    m_oPlayer.nWidth = 16;
    m_oPlayer.nHeight = 24;

    // Setup a meta sprite for the player
    // register each sprite with the system
    // save the sprite information in the spriteIDs array
    
    // Tile 0, sprite 0
    set_sprite_tile(0,0);
    m_oPlayer.ubSpriteIDs[0] = 0;
    
    // Tile 1, sprite 2
    set_sprite_tile(1,1);
    m_oPlayer.ubSpriteIDs[1] = 1;
    
    // Tile 2, sprite 2
    set_sprite_tile(2,2);
    m_oPlayer.ubSpriteIDs[2] = 2;
    
    // Tile 3, sprite 3
    set_sprite_tile(3,3);
    m_oPlayer.ubSpriteIDs[3] = 3;

    // Tile 3, sprite 4
    set_sprite_tile(4,4);
    m_oPlayer.ubSpriteIDs[4] = 4;

    // Tile 3, sprite 5
    set_sprite_tile(5,5);
    m_oPlayer.ubSpriteIDs[5] = 5;

    // Set the inital postion of the player
    MovePlayerCharacter(&m_oPlayer, m_oPlayer.nX, m_oPlayer.nY);
}

//--------------------------------------------------------------------------------------
// SetupPlayerBG: Initalize the background for the player, used to make the player
// look as though it is digging.
//--------------------------------------------------------------------------------------
void SetupPlayerBG()
{
    // Change the colors to allow black 
    // to be the traparent color
    OBP0_REG = 0xE0;

    // Layer 5 
    set_sprite_tile(6, 6);
    move_sprite(6, 67, 49);

    set_sprite_tile(7, 6);
    move_sprite(7, 72, 49);

    set_sprite_tile(8, 6);
    move_sprite(8, 88, 49);

    set_sprite_tile(9, 6);
    move_sprite(9, 91, 49);

    set_sprite_tile(10, 6);
    move_sprite(10, 99, 49);

    set_sprite_tile(11, 6);
    move_sprite(11, 101, 49);

    // Layer 4, Left Side
    set_sprite_tile(12, 6);
    move_sprite(12, 67, 43);

    set_sprite_tile(13, 6);
    move_sprite(13, 72, 43);

    set_sprite_tile(14, 6);
    move_sprite(14, 67, 35);

    set_sprite_tile(15, 6);
    move_sprite(15, 72, 35);

    // Layer 4, Right Side
    set_sprite_tile(16, 6);
    move_sprite(16, 94, 43);

    set_sprite_tile(17, 6);
    move_sprite(17, 101, 43);

    set_sprite_tile(18, 6);
    move_sprite(18, 94, 35);

    set_sprite_tile(19, 6);
    move_sprite(19, 101, 35);

    // Layer 3
    set_sprite_tile(20, 6);
    move_sprite(20, 67, 27);

    set_sprite_tile(21, 6);
    move_sprite(21, 75, 27);

    set_sprite_tile(22, 6);
    move_sprite(22, 83, 27);

    set_sprite_tile(23, 6);
    move_sprite(23, 91, 27);

    set_sprite_tile(24, 6);
    move_sprite(24, 99, 27);

    set_sprite_tile(25, 6);
    move_sprite(25, 101, 27);
    
    // Layer 2
    set_sprite_tile(26, 6);
    move_sprite(26, 67, 19);

    set_sprite_tile(27, 6);
    move_sprite(27, 75, 19);

    set_sprite_tile(28, 6);
    move_sprite(28, 83, 19);

    set_sprite_tile(29, 6);
    move_sprite(29, 91, 19);

    set_sprite_tile(30, 6);
    move_sprite(30, 99, 19);

    set_sprite_tile(31, 6);
    move_sprite(31, 101, 19);

    // Layer 1
    set_sprite_tile(32, 6);
    move_sprite(32, 67, 11);

    set_sprite_tile(33, 6);
    move_sprite(33, 75, 11);

    set_sprite_tile(34, 6);
    move_sprite(34, 83, 11);

    set_sprite_tile(35, 6);
    move_sprite(35, 91, 11);

    set_sprite_tile(36, 6);
    move_sprite(36, 99, 11);

    set_sprite_tile(37, 6);
    move_sprite(37, 101, 11);
}

//--------------------------------------------------------------------------------------
// PerformantDelay: A function for delaying the system based on screen draws
// 
// Params:
//      nLoops: Number of times to wait for the screen to redraw.
//--------------------------------------------------------------------------------------
void PerformantDelay(UINT8 nLoops)
{
    // new uint8 for the for loop index
    UINT8 i;

    // Loop through however many loops are required
    for (i = 0; i < nLoops; i++)
    {
        // wait for one screen has been drawn
        // gives a less cpu strain delay
        wait_vbl_done();
    }
}

//--------------------------------------------------------------------------------------
// FadeBackground: A universal function for fading in or out the background layer with
// custom color choices and delay.
//
// Helpful:
//      00: White,
//      01: Light Grey,
//      10: Dark Grey,
//      11: Black.
//      Convert to hexadecimal: eg. 0x27 = 00 10 01 11
//
// Params:
//      bMode: 0 or 1 for Fade Out or Fade In.
//      nValue1: The first color change in hexadecimal.
//      nValue2: The second color change in hexadecimal.
//      nValue3: The third color change in hexadecimal.
//      nValue4: The fourth color change in hexadecimal.
//      nDelay: The amount of frames it takes to get through thr fade.
//--------------------------------------------------------------------------------------
void FadeBackground(BYTE bMode, UINT8 nValue1, UINT8 nValue2, UINT8 nValue3, UINT8 nValue4, UINT8 nDelay)
{
    // The amount of times to loop, based
    // on if it is a fade out or fade in
    UINT8 nLoopAmount;

    // if the mode value is set to 1 set the loop amount
    // to 4, this is for the fade out.
    if (bMode == 1)
    {
        nLoopAmount = 4;
    }

    // else if the value is 0 set the loop amount to 3
    // This is for Fade In.
    else
    {
        nLoopAmount = 3;
    }

    // Loop through however many colors are needed for the fade.
    for(m_nFadeIndex = 0; m_nFadeIndex < nLoopAmount; m_nFadeIndex++)
    {
        // Switch statement for setting background color for each
        // iteration through the for loop
        switch(m_nFadeIndex)
        {
            case 0:
                BGP_REG = nValue1;
            break;

            case 1:
                BGP_REG = nValue2;
            break;

            case 2:
                BGP_REG = nValue3;
            break;

            case 3:
                BGP_REG = nValue4;
            break;
        }

        // Hold program, this is for the speed of the fade
        PerformantDelay(nDelay);
    }
}

//--------------------------------------------------------------------------------------
// DisplaySplashScreen: Set data and display everything needed for the Splash Screen.
//--------------------------------------------------------------------------------------
void DisplaySplashScreen()
{
    // Change the colors to allow black 
    // to be the traparent color for the 
    // background.

    //0x27 = 00 10 01 11
    // 00: White,
    // 01: Light Grey,
    // 10: Dark Grey,
    // 11: Black.
    BGP_REG = 0x27;

    // Set data and tiles for the background layer
    set_bkg_data(37, 55, m_caSplashTiles);
    set_bkg_tiles(0, 0, 20, 18, m_caSplashMap);

    // Wait a few frames and then fade out splash screen
    PerformantDelay(100);
    FadeBackground(1, 0x67, 0xBB, 0xFB, 0xFF, 15);
}

//--------------------------------------------------------------------------------------
// DisplaySplashScreen: Set data and display everything needed for the Start Screen.
//--------------------------------------------------------------------------------------
void DisplayStartScreen()
{
    // Set data and tiles for the background layer
    set_bkg_data(93, 49, m_caBgTiles);
    set_bkg_tiles(0, 0, 20, 18, m_caStartScreen);

    // Fade in the start screen from previous background
    FadeBackground(0, 0xFB, 0xBB, 0xE4, 0x00, 15);

    // Print Press start text  
    printf("\n\n\n\n\n\n\n\n\n====PRESS  START====");

    // Hold programm until the start button is pressed
    waitpad(J_START);

    // Play the start sound after button press
    NR41_REG = 0x13;
    NR42_REG = 0x35;
    NR43_REG = 0x28;
    NR44_REG = 0xC0;  
    
    // Small delay to allow sound to play
    PerformantDelay(2);
}

//--------------------------------------------------------------------------------------
// Initialize: Prepare the application for launch.
//--------------------------------------------------------------------------------------
void Initialize()
{
    // New font variable
    font_t tMinFont;

    // initiate new font variable with built in font "min"
    // this is the smallest font in the system and is 36 tiles/sprites
    font_init();
    tMinFont = font_load(font_min);
    font_set(tMinFont);

    // Sound registers, must be in this order.
    NR52_REG = 0x80; // Turn on the sound.
    NR50_REG = 0x77; // Set the volume of the left and right channel
    NR51_REG = 0xFF; // Set usage to both channels

    // Display the splash screen background
    DisplaySplashScreen();

    // Display the start screen background
    DisplayStartScreen();

    // Set the background pos values
    m_nBackgroundPos[0] = 0;
    m_nBackgroundPos[1] = 0;

    // Set the level background data
    set_bkg_tiles(m_nBackgroundPos[0], m_nBackgroundPos[1], 20, 500, m_caBackground);

    // Set sprite data based on spritesheet
    // There are 7 tiles
    set_sprite_data(0, 7, m_caSprites);

    // Setup inital values for player background
    // and the player object
    SetupPlayerBG();    
    SetupPlayer();

    // Display the sprite and
    // the background layers
    SHOW_SPRITES;
    SHOW_BKG;

    // Turn on GameBoy display
    DISPLAY_ON;
}

//--------------------------------------------------------------------------------------
// main: base function of the program where all code will be run.
//--------------------------------------------------------------------------------------
void main()
{
    // Initialize layers, 
    // player, spirtes, bg, etc
    Initialize();

    // Create the main game loop of the application
    while (1)
    {
        // If the A button is pressed.
        if (joypad() & J_A)
        {
            // Play the dig sound
            NR41_REG = 0x1F;
            NR42_REG = 0x44;
            NR43_REG = 0x62;
            NR44_REG = 0xC0;  
    
            // Small delay to allow sound to play
            PerformantDelay(2);

            // Wait for the button to be 
            // released before moving on
            waitpadup();

            // Update the position variable of the background by 1
            m_nBackgroundPos[1] = m_nBackgroundPos[1] + 2;

            // Increment the dialog index
            m_nDialogIndex = m_nDialogIndex + 1;

            // move the background layer
            move_bkg(m_nBackgroundPos[0], m_nBackgroundPos[1]);
        }

        // If the background gets to level 100
        if (m_nBackgroundPos[1] >= 100)
        {
            // Push the background postion backwards
            m_nBackgroundPos[1] = 55;

            // Move the background layer
            move_bkg(m_nBackgroundPos[0], m_nBackgroundPos[1]);
        }

        // Switch statement to display different dialog at
        // different levels of the background shift
        switch(m_nDialogIndex)
        {
            // At depth 10 display "HOPE UR NOT BORED" dialog
            case 10:
                SetDialog(m_caDialog1, 20, 1, 9, 136);
                SHOW_WIN;
            break;

            // At depth 20 display "COS UR ABOUT TO BE" dialog
            case 20:
                SetDialog(m_caDialog2, 18, 1, 9, 136);
            break;

            // At depth 30 hide the window layer for now
            case 30:
                HIDE_WIN;
            break;

            // At depth 50 display "WELCOME TO DIGGING" dialog
            case 50:
                SetDialog(m_caDialog3, 18, 1, 9, 136);
                SHOW_WIN;
            break;

            // At depth 65 display "AND ONLY DIGGING" dialog
            case 65:
                SetDialog(m_caDialog4, 17, 1, 9, 136);
            break;

            // At depth 80 hide the window layer for now
            case 80:
                HIDE_WIN;
            break;

            // At depth 105 display " THOUGHT I WAS JOKING" dialog
            case 105:
                SetDialog(m_caDialog5, 19, 1, 9, 136);
                SHOW_WIN;
            break;

            // At depth 125 display "NO THIS IS IT SORRY" dialog
            case 125:
                SetDialog(m_caDialog6, 19, 1, 9, 136);
            break;

            // At depth 140 hide the window layer for now
            case 140:
                HIDE_WIN;
            break;

            // At depth 215 display "WHY U STILL HERE" dialog
            case 215:
                SetDialog(m_caDialog7, 19, 1, 9, 136);
                SHOW_WIN;
            break;

            // At depth 230 hide the window layer for now
            case 230:
                HIDE_WIN;
            break;

            // At depth 250, set the dialog index back as its getting
            // to the end of the int range. So the game will run forever
            // from here. cool.
            case 250:
                m_nDialogIndex = 235;

                // Flip the background colors
                BGP_REG = 0xBB;
            break;
        }

        // Run a small delay to stop everything from
        // moving too quickly
        PerformantDelay(6);
    }
}