#include "raylib.h"
#include <string>

struct AnimData
{
    Rectangle rec;
    Vector2 pos;
    int frame;
    float updateTime;
    float runntingTime;
};

bool isOnGround(AnimData data, int windowHeight)
{
   return data.pos.y >= (windowHeight - 80) - data.rec.height;
}
AnimData updateAnimData(AnimData data, float dT, int maxFrame)
{
    data.runntingTime += dT;
    if (data.runntingTime >= data.updateTime)
    {
        data.runntingTime = 0.0;
        data.rec.x = data.frame * data.rec.width;
        data.frame++;
        if (data.frame > maxFrame)
        {
            data.frame = 0;
        }
    }
    return data;
}

void UnlockAchievement(const char* achievementName)
{
    DrawText(achievementName, 50, 100, 20, GOLD);
    printf("Achievement Unlocked: %s\n", achievementName);
}

int main()
{
    int WindowDimensions [2];
    WindowDimensions [0] = 1280;
    WindowDimensions [1] = 720;

    //window dimensions
    const int windowWidth {WindowDimensions [0]};
    const int windowHeight {WindowDimensions [1]};

    InitWindow(WindowDimensions[0], WindowDimensions[1], "Dinodash");

    //Sounds
    InitAudioDevice();
    Sound Jump = LoadSound("assets/Sounds/jump.wav");
    Sound duckSound = LoadSound("assets/Sounds/jump.wav");
    Sound melonPickUp = LoadSound("assets/Sounds/pickupCoin.wav");
    Sound shieldpickup = LoadSound("assets/Sounds/pickupCoin.wav");
    Sound kill = LoadSound("assets/Sounds/hitHurt.wav");
    Music PixelKing = LoadMusicStream("assets/Sounds/Pixel Kings.wav");
    PlayMusicStream(PixelKing);


    // Texture Backround
    Texture2D mountain =LoadTexture("assets/textures/mountain.png");
    AnimData mountainData;
    mountainData.rec.width = mountain.width;
    mountainData.rec.height = mountain.height;
    mountainData.rec.x = 0;
    mountainData.rec.y = 0;
    mountainData.pos.x = 0;
    mountainData.pos.y = 0;
    mountainData.frame = 0;
    mountainData.runntingTime = 0;
    mountainData.updateTime =0;

    // Cloud data for multiple clouds
    Texture2D clouds = LoadTexture("assets/textures/cloud.png");
    const int numClouds = 4;
    AnimData cloudsData[numClouds];
    for (int i = 0; i < numClouds; i++)
    {
        cloudsData[i].rec.width = clouds.width;
        cloudsData[i].rec.height = clouds.height;
        cloudsData[i].rec.x = 0;
        cloudsData[i].rec.y = 0;
        cloudsData[i].pos.x = windowWidth + GetRandomValue(200 * i, 400 * i); // Staggered start positions
        cloudsData[i].pos.y = GetRandomValue(50, 150); // Random height in the sky
        cloudsData[i].frame = 0;
        cloudsData[i].runntingTime = 0;
        cloudsData[i].updateTime = 0;
    }

    // Distant mountains animation data
    Texture2D distantMountain = LoadTexture("assets/textures/distant_mountain.png");
    AnimData distantMountainData;
    distantMountainData.rec.width = distantMountain.width;
    distantMountainData.rec.height = distantMountain.height;
    distantMountainData.rec.x = 0;
    distantMountainData.rec.y = 0;
    distantMountainData.pos.x = 0;
    distantMountainData.pos.y = windowHeight - 700;
    distantMountainData.frame = 0;
    distantMountainData.runntingTime = 0;
    distantMountainData.updateTime = 0;

    Texture2D birds =LoadTexture("assets/textures/birds.png");
    AnimData birdsData;
    birdsData.rec.width = birds.width;
    birdsData.rec.height = birds.height;
    birdsData.rec.x = 0;
    birdsData.rec.y = 0;
    birdsData.pos.x = 0;
    birdsData.pos.y = 0;
    birdsData.frame = 0;
    birdsData.runntingTime = 0;
    birdsData.updateTime =0;

    Texture2D treesBack =LoadTexture("assets/textures/treesBack.png");
    AnimData treesBackData;
    treesBackData.rec.width = treesBack.width;
    treesBackData.rec.height = treesBack.height;
    treesBackData.rec.x = 0;
    treesBackData.rec.y = 0;
    treesBackData.pos.x = treesBack.width;
    treesBackData.pos.y = 0;
    treesBackData.frame = 0;
    treesBackData.runntingTime = 0;
    treesBackData.updateTime =0;

Texture2D treesFront =LoadTexture("assets/textures/treesFront.png");
    AnimData treesFrontData;
    treesFrontData.rec.width = treesFront.width;
    treesFrontData.rec.height = treesFront.height;
    treesFrontData.rec.x = 0;
    treesFrontData.rec.y = 0;
    treesFrontData.pos.x = treesFront.width;
    treesFrontData.pos.y = 0;
    treesFrontData.frame = 0;
    treesFrontData.runntingTime = 0;
    treesFrontData.updateTime =0;

    Texture2D dayBackground = LoadTexture("assets/textures/day.png");
    Texture2D nightBackground = LoadTexture("assets/textures/starrynight.png");
    Texture2D moonTexture = LoadTexture("assets/textures/moon.png");
    Texture2D sunTexture = LoadTexture("assets/textures/sun.png");

    //Textures Dino

    Texture2D Dino = LoadTexture("assets/textures/dino.png");
    AnimData dinoData;
    dinoData.rec.width = Dino.width/4;
    dinoData.rec.height = Dino.height;
    dinoData.rec.x = 0;
    dinoData.rec.y = 0;
    dinoData.pos.x = windowWidth/3 - dinoData.rec.width/2;
    dinoData.pos.y = ((windowHeight - 80) - dinoData.rec.height);
    dinoData.frame = 0;
    dinoData.runntingTime = 0;
    dinoData.updateTime =  0.1;


    //Texture Laeva
    Texture2D Laeva = LoadTexture("assets/textures/LAEVA.png");
    const int NumOfLaevas{6};
    int LaevaDist{100};

    AnimData Laevas[NumOfLaevas];
    for (int i = 0; i < NumOfLaevas; i++)
    {
        Laevas[i].rec.x = 0.0;
        Laevas[i].rec.y = 0.0;
        Laevas[i].rec.width = Laeva.width/4;
        Laevas[i].rec.height = Laeva.height;
        Laevas[i].pos.x = windowWidth + LaevaDist;
        Laevas[i].pos.y = (windowHeight - 100) - Laeva.height;
        Laevas[i].frame = 0.0;
        Laevas[i].runntingTime = 0.0;
        Laevas[i].updateTime = 0.2;
        LaevaDist += 10000;
    }

    //Texture Watermelon
    Texture2D melon = LoadTexture("assets/textures/Yellow Watermelon2.png");
    const int NumOfMelon{1};
    int MelonDist{1000};

    AnimData Melons[NumOfMelon];
    for (int i = 0; i < NumOfMelon; i++)
    {
        Melons[i].rec.x = 0.0;
        Melons[i].rec.y = 0.0;
        Melons[i].rec.width = melon.width;
        Melons[i].rec.height = melon.height;
        Melons[i].pos.x = windowWidth + MelonDist;
        Melons[i].pos.y = (windowHeight - 200) - melon.height;
        Melons[i].frame = 0.0;
        Melons[i].runntingTime = 0.0;
        Melons[i].updateTime = 0.2;
        MelonDist += 2000;
    }

    // Texture Shield
    Texture2D shieldTexture = LoadTexture("assets/textures/shield.png");
    shieldTexture = LoadTexture("assets/textures/shield.png");

    if (shieldTexture.id == 0) {
        printf("Failed to load shield texture.\n");
        } else {
            printf("Shield texture loaded successfully!\n");
            }
    const int NumOfShields{1}; // Only one shield at a time
    AnimData Shields[NumOfShields];

    for (int i = 0; i < NumOfShields; i++)
    {
        Shields[i].rec.x = 0.0;
        Shields[i].rec.y = 0.0;
        Shields[i].rec.width = shieldTexture.width;
        Shields[i].rec.height = shieldTexture.height;
        Shields[i].pos.x = windowWidth + GetRandomValue(2500, 10000);
        Shields[i].pos.y = (windowHeight - GetRandomValue(150, 300)) - shieldTexture.height; // Near the ground
        Shields[i].frame = 0;
        Shields[i].runntingTime = 0.0;
        Shields[i].updateTime = 0.0; // No animation for now
    }
    //Dino Is ducking
    bool DinoIsDuck{false};
    // Dino Velocity
    int Dino_velocity{0};
    // Dino Jump Hight (pixels/s/s)/frame
    const int jump_hight{800};
    //Gravity (pixels/s/s)/frame
    const int gravity{2'000};
    //Object Speed
    float ObjectSpeed{300};
    //Back speed
    float mountainSpeed{30};
    float birdsSpeed{20};
    float treesFrontSpeed{100};
    float treesBackSpeed{70};
    // Cloud speed
    float cloudsSpeed{5};
    // Distant mountains speed
    float distantMountainSpeed{10};
    //points
    int pointNum{0};
    float pointRunningTime{0};
    float pointUpdateTime {1};
    //Duck cooldown
    float DuckRunningTime{0};
    float DuckUpdateTime {0.45};
    //Collisions
    bool LaevaCollisions{false};
    bool MelonCollisions{false};
    //Shield Colloison
    bool ShieldActive{false};
    float ShieldDuration{0.0f};
    // Achievements
    bool achievementsUnlocked[3] = {false, false, false}; // 3 achievements for now
    //Menu
    bool Menu{true};
    bool MusicOn{true};
    
    //Timer for day night shifts
    float dayNightCycleTime = 0.0f; // Timer
    float cycleDuration = 45.0f;    // Duration for one phase (45 seconds for day, 45 for night)
    bool isNight = false;          

    // sun position
    Vector2 sunPosition = {900, 20};
    // Initial moon position
    Vector2 moonPosition = {900, 100}; 

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {   
        //Logic update for day-night cycle 
        float dt = GetFrameTime();

        // Update day-night cycle timer
        dayNightCycleTime += dt;
        if (dayNightCycleTime >= cycleDuration) 
        {
            isNight = !isNight; // Toggle between day and night
            dayNightCycleTime = 0.0f; // Reset the cycle timer
        }

        // Moon position update logic (before rendering)
        if (isNight) 
        {
            moonPosition.x -= 6 * dt; // Moon moves left slowly
            if (moonPosition.x < -100) 
            {
                moonPosition.x = windowWidth + 100; // Reset moon position after leaving the screen
            }
        }

        BeginDrawing();
        ClearBackground(WHITE);
    if(Menu)
    {
            DrawText("Welcome to the Story of Glino the Dino!",
            100, 100, 40, BLACK);
            DrawText("It wasn't asteriods that killed the Dinos...",
            100, 150, 40, BLACK);
            DrawText("It was an axe called Laeva!",
            100, 200, 40, RED);
            DrawText("Help Glino avoiding certain DEATH!",
            100, 250, 40, BLACK);
            DrawTextureRec(Dino, dinoData.rec, dinoData.pos, WHITE);
            DrawText("CONTROLS",
            850, 450, 40, RED);
            DrawText(">>SPACE<< TO JUMP OVER AXES",
            800, 500, 20, BLUE);
            DrawText(">>S<< TO DUCK UNDER AXES",
            800, 550, 20, BLUE);
            DrawText(">>Q<< TO TURN MUSIC OFF",
            800, 600, 20, BLUE);
            DrawText(">>E<< TO TURN MUSIC ON",
            800, 650, 20, BLUE);
            DrawText("ENTER TO START",
            100, 400, 60, RED);

            int achievementY = 500;
            if (achievementsUnlocked[0])
            {
                DrawText("Achievement: First 50 Points!", 50, achievementY, 20, GOLD);
                achievementY += 30;
            }
            if (achievementsUnlocked[1])
            {
                DrawText("Achievement: Scored 100 Points!", 100, achievementY, 20, GOLD);
                achievementY += 30;
            }
            if (achievementsUnlocked[2])
            {
                DrawText("Achievement: Survived 5 Minutes!", 400, achievementY, 20, GOLD);
                achievementY += 30;
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                Menu = false;
            }
            if (MusicOn)
            {
                UpdateMusicStream(PixelKing);
            }
            if (IsKeyPressed(KEY_Q))
            {
                MusicOn = false;
            }

    }
    else
    {

        

        if (LaevaCollisions)
        {


            DrawText("Game Over, Dino Died :(", windowWidth/2 - 200, 200, 60, RED);
            std::string points = "Score: ";
            DrawText("ENTER TO RESTART", windowWidth/2 - 200, 300, 60, RED);
            points.append(std::to_string(pointNum), 0, 999);
            DrawText(points.c_str(), windowWidth/2 - 200, 400, 30, BLUE);

            StopMusicStream(PixelKing);
            DrawText("CONTROLS",
            850, 450, 40, RED);
            DrawText(">>SPACE<< TO JUMP OVER AXES",
            800, 500, 20, BLUE);
            DrawText(">>S<< TO DUCK UNDER AXES",
            800, 550, 20, BLUE);
            DrawText(">>Q<< TO TURN MUSIC OFF",
            800, 600, 20, BLUE);
            DrawText(">>E<< TO TURN MUSIC ON",
            800, 650, 20, BLUE);

            int achievementY = 500;
            if (achievementsUnlocked[0])
            {
                DrawText("Achievement: First 50 Points!", 50, achievementY, 20, GOLD);
                achievementY += 30;
            }
            if (achievementsUnlocked[1])
            {
                DrawText("Achievement: Scored 100 Points!", 100, achievementY, 20, GOLD);
                achievementY += 30;
            }
            if (achievementsUnlocked[2])
            {
                DrawText("Achievement: Survived 5 Minutes!", 400, achievementY, 20, GOLD);
                achievementY += 30;
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                LaevaCollisions = false;
                pointNum = 0;

                int LaevaDist = 100;
                for (int i = 0; i < NumOfLaevas; i++)
                {
                    Laevas[i].rec.x = 0.0;
                    Laevas[i].rec.y = 0.0;
                    Laevas[i].rec.width = Laeva.width/4;
                    Laevas[i].rec.height = Laeva.height;
                    Laevas[i].pos.x = windowWidth + LaevaDist;
                    Laevas[i].pos.y = (windowHeight - 100) - Laeva.height;
                    Laevas[i].frame = 0.0;
                    Laevas[i].runntingTime = 0.0;
                    Laevas[i].updateTime = 0.2;
                    LaevaDist += 10000;
                }

                for (int i = 0; i < NumOfMelon; i++)
                {
                Melons[i].pos.x = windowWidth + GetRandomValue(2000,20000) ;
                }
                ObjectSpeed = 300;
                mountainSpeed = 30;
                birdsSpeed = 20;
                treesFrontSpeed =100;
                treesBackSpeed = 70;
            }
        }


        else
        {
        if (dinoData.pos.y > (windowHeight - 80) - dinoData.rec.height)
        {
            dinoData.pos.y = (windowHeight - 80) - dinoData.rec.height;
        }

        //Music Logic
        if (MusicOn) {
            UpdateMusicStream(PixelKing);
            }
        if (IsKeyPressed(KEY_Q) && MusicOn) {
            MusicOn = false;
            StopMusicStream(PixelKing);
            printf("Music stopped.\n");
            }

        if (IsKeyPressed(KEY_E) && !MusicOn) {
            MusicOn = true;
            PlayMusicStream(PixelKing);
            printf("Music started.\n");
            }


        //Delta Time
        float dt{GetFrameTime()};

        // Update timer for day-night cycle
        dayNightCycleTime += dt;
        if (dayNightCycleTime >= cycleDuration) 
        {
            isNight = !isNight;         // Toggle day/night state
            dayNightCycleTime = 0.0f;   // Reset timer
        }
        
        if (isNight) 
        {
            moonPosition.x -= 20 * dt; // Moon moves leftwards
            if (moonPosition.x < -100) 
            {
                moonPosition.x = windowWidth + 100; // Reset after exiting the screen
            }
        }

        //Game Logic

        //Points Health
        pointRunningTime += dt;
        if (pointRunningTime >= pointUpdateTime)
        {
        pointRunningTime = 0.0;
        pointNum++;
        if (ObjectSpeed<700)
        {
            ObjectSpeed+=10;
            mountainSpeed+=2;
            treesBackSpeed+=4;
            treesFrontSpeed+=6;

            cloudsSpeed = ObjectSpeed * 0.03f;          // Clouds move slower
            distantMountainSpeed = ObjectSpeed * 0.06f; // Distant mountains move slightly faster

        }
        }

        if (!achievementsUnlocked[0] && pointNum >= 50)
        {
            achievementsUnlocked[0] = true;
            UnlockAchievement("First 50 Points!");
        }

        if (!achievementsUnlocked[1] && pointNum >= 100)
        {
            achievementsUnlocked[1] = true;
            UnlockAchievement("Scored 100 Points!");
        }

        if (!achievementsUnlocked[2] && pointNum >= 400)
        {
            achievementsUnlocked[2] = true;
            UnlockAchievement("Survived 5 Minutes!");
        }


        std::string points = "Score: ";
        points.append(std::to_string(pointNum), 0, 999);
        DrawText(points.c_str(), windowWidth/2 - 200, 100, 30, RED);


        // Ground check
        if (isOnGround(dinoData, windowHeight))
        {
            Dino_velocity = 0;
        }
        else{
            //Apply gravity
        Dino_velocity += gravity * dt;

        }

        // Collision with Shield Power-Up
        for (int i = 0; i < NumOfShields; i++)
        {
            float ShieldPad{5};
            Rectangle ShieldRec
            {
                Shields[i].pos.x + ShieldPad,
                Shields[i].pos.y + ShieldPad,
                Shields[i].rec.width - 2 * ShieldPad,
                Shields[i].rec.height - 2 * ShieldPad
            };
            float DinoPad{30};
            Rectangle dinoRec
            {
                dinoData.pos.x + DinoPad,
                dinoData.pos.y + DinoPad,
                dinoData.rec.width - 2 * DinoPad,
                dinoData.rec.height - 2 * DinoPad
            };

            if (CheckCollisionRecs(ShieldRec, dinoRec))
            {
                // Activate shield
                ShieldActive = true;
                ShieldDuration = 3.0f; // Shield lasts 3 seconds
                PlaySound(shieldpickup);
                Shields[i].pos.x = windowWidth + GetRandomValue(2500, 10000); // Respawn shield & Random X
                Shields[i].pos.y = (windowHeight - GetRandomValue(150, 300)) - shieldTexture.height; // Random Y near the ground

            }

        }
        // Handle Shield Duration
        if (ShieldActive)
        {
            ShieldDuration -= GetFrameTime();
            if (ShieldDuration <= 0.0f)
            {
            ShieldActive = false; // Deactivate shield when time runs out
            }
        }

        for (AnimData Laeva :Laevas)
        {
            float Laevpad{30};
            Rectangle LaevRec {
                Laeva.pos.x + Laevpad,
                Laeva.pos.y + Laevpad,
                Laeva.rec.width - 2*Laevpad,
                Laeva.rec.height - 2*Laevpad
            };
            float DinoPad{30};
            Rectangle dinoRec {
                dinoData.pos.x + DinoPad,
                dinoData.pos.y + DinoPad,
                dinoData.rec.width - 2*DinoPad,
                dinoData.rec.height - 2*DinoPad
            };

            if (CheckCollisionRecs(LaevRec, dinoRec) && !DinoIsDuck && !ShieldActive)
            {
                LaevaCollisions = true;
                PlaySound(kill);
            }


        }
        //Duck
        if ((IsKeyPressed(KEY_S)))
        {
            DinoIsDuck = true;
            PlaySound(duckSound);
        }
        if (DinoIsDuck && DuckRunningTime < DuckUpdateTime)
        {
            DuckRunningTime += dt;

            dinoData.rec.x = 3*dinoData.rec.width;
        }
        else
        {
        DuckRunningTime = 0.0;
        DinoIsDuck =false;

        //update animData Dino
        dinoData = updateAnimData(dinoData, dt, 2);
        }

        //update AnimData Laeva
        for (int i = 0; i < NumOfLaevas; i++)
        {
            Laevas[i] = updateAnimData(Laevas[i], dt, 3);
        }

        //Jump
        if ((IsKeyPressed(KEY_SPACE) && isOnGround(dinoData, windowHeight))||(IsKeyPressed(KEY_W) && isOnGround(dinoData, windowHeight)))
        {
            Dino_velocity -= jump_hight;
            PlaySound(Jump);
        }
        //Collisions Check
        for (AnimData Melon :Melons)
        {
            float MelonPad{5};
            Rectangle MelonRec {
                Melon.pos.x + MelonPad,
                Melon.pos.y + MelonPad,
                Melon.rec.width - 2*MelonPad,
                Melon.rec.height - 2*MelonPad
            };
            float DinoPad{30};
            Rectangle dinoRec {
                dinoData.pos.x + DinoPad,
                dinoData.pos.y + DinoPad,
                dinoData.rec.width - 2*DinoPad,
                dinoData.rec.height - 2*DinoPad
            };

            if (CheckCollisionRecs(MelonRec, dinoRec))
            {
                PlaySound(melonPickUp);
                pointNum += 10;
                Melons[0].pos.x = windowWidth + GetRandomValue(2000,20000);
            }
        }


        //update position DINO
        dinoData.pos.y += Dino_velocity * dt;


        //Update position LAEVA
        for (int i = 0; i < NumOfLaevas; i++)
        {

            if (Laevas[i].pos.x <= 0)
            {
                Laevas[i].pos.x = windowWidth + i*GetRandomValue(100,500);
            }
            else{
            Laevas[i].pos.x -= (ObjectSpeed) * dt;
            }
        }

        //Update position Melon
        for (int i = 0; i < NumOfMelon; i++)
        {

            if (Melons[i].pos.x <= 0)
            {
                Melons[i].pos.x = windowWidth + GetRandomValue(2000,20000) ;
            }
            else{
            Melons[i].pos.x -= (ObjectSpeed) * dt;
            }
        }
        //Update position Shield
        for (int i = 0; i < NumOfShields; i++)
        {
            // If the shield moves off-screen, respawn it
            if (Shields[i].pos.x <= 0)
            {
                Shields[i].pos.x = windowWidth + GetRandomValue(2500, 10000);  // Spawn closer to the right
                Shields[i].pos.y = (windowHeight - GetRandomValue(150, 300)) - shieldTexture.height; // Random height
            }
            else
            {
                // Move shield leftwards
                Shields[i].pos.x -= ObjectSpeed * dt;
            }
        }


        //update position Back
        if (mountainData.pos.x <= -mountain.width)
        {
            mountainData.pos.x = mountain.width;
        }
        else
        {
            mountainData.pos.x -= mountainSpeed * dt;
        }

        //cloud updated logic
        for (int i = 0; i < numClouds; i++)
        {
            if (cloudsData[i].pos.x <= -clouds.width)
            {
                cloudsData[i].pos.x = windowWidth + GetRandomValue(0, 100); // Reset to the right
                cloudsData[i].pos.y = GetRandomValue(50, 150); // Randomize height
            }
            else
            {
                cloudsData[i].pos.x -= cloudsSpeed * dt; // Move left
            }
        }

        // Move distant mountains
        if (distantMountainData.pos.x <= -distantMountain.width)
        {
            distantMountainData.pos.x = windowWidth + GetRandomValue(0, 450); // Reset position + increase appearing freq
        }
        else
        {
            distantMountainData.pos.x -= distantMountainSpeed * dt; // update - Distant mountains move faster than clouds
        }



        if (birdsData.pos.x <= -200)
        {
            birdsData.pos.x = 10000;
        }
        else
        {
            birdsData.pos.x -= birdsSpeed*dt;
        }

        if (treesFrontData.pos.x <= -treesFront.width)
        {
            treesFrontData.pos.x = treesFront.width;
        }
        else
        {
            treesFrontData.pos.x -= ObjectSpeed*dt;
        }

        if (treesBackData.pos.x <= -treesBack.width)
        {
            treesBackData.pos.x = treesBack.width;
        }
        else
        {
            treesBackData.pos.x -= treesBackSpeed*dt;
        }
        
        // Background Rendering
        if (isNight) 
        {
            DrawTexture(nightBackground, 0, 0, WHITE); // Starry night background
            DrawTextureEx(moonTexture, moonPosition, 0.0f, 0.05f, WHITE); // Moon
        } 
        else 
        {
            DrawTexture(dayBackground, 0, 0, WHITE); // Daytime background
            //Render the sum during the day
            DrawTextureEx(sunTexture, sunPosition, 0.0f, 0.5f, WHITE); // Sun texture
        }
        
        // Foreground Elements
        DrawLine(0, (windowHeight - 350) + dinoData.rec.height, windowWidth, (windowHeight - 350) + dinoData.rec.height, BLACK);
        DrawTextureRec(mountain, mountainData.rec, mountainData.pos, WHITE);
        for (int i = 0; i < numClouds; i++)
        {
            DrawTextureRec(clouds, cloudsData[i].rec, cloudsData[i].pos, WHITE);
        }
        DrawTextureRec(distantMountain, distantMountainData.rec, distantMountainData.pos, WHITE);
        DrawTextureRec(birds,birdsData.rec, birdsData.pos, WHITE);
        DrawTextureRec(treesBack, treesBackData.rec, treesBackData.pos, WHITE);
        DrawTextureRec(treesFront, treesFrontData.rec, treesFrontData.pos, WHITE);

        DrawLine(0, (windowHeight - 250) + dinoData.rec.height, windowWidth, (windowHeight - 250) + dinoData.rec.height, BLACK);
        
        //Game Elements

        DrawTextureRec(Dino, dinoData.rec, dinoData.pos, WHITE);

        for (int i = 0; i < NumOfLaevas; i++)
        {
            DrawTextureRec(Laeva, Laevas[i].rec, Laevas[i].pos, WHITE);
        }
        for (int i = 0; i < NumOfMelon; i++)
        {
            DrawTextureRec(melon, Melons[i].rec, Melons[i].pos, WHITE);
        }
        for (int i = 0; i < NumOfShields; i++)
        {
            DrawTextureRec(shieldTexture, Shields[i].rec, Shields[i].pos, WHITE);
        }
        for (int i = 0; i < numClouds; i++)
        {
            DrawTextureRec(clouds, cloudsData[i].rec, cloudsData[i].pos, WHITE);
        }




    }
    }



        EndDrawing();




    }
    UnloadTexture(Dino);
    UnloadTexture(Laeva);
    UnloadTexture(melon);
    UnloadTexture(shieldTexture);
    UnloadTexture(clouds);
    UnloadTexture(distantMountain);
    UnloadTexture(dayBackground);
    UnloadTexture(nightBackground);
    UnloadTexture(sunTexture);
    UnloadTexture(moonTexture);



    CloseWindow();


}