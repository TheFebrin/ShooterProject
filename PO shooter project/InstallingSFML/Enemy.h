#pragma once
#ifndef Enemy_h

#include<iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<math.h>
#include<vector>
#include<cstdlib>

#include "Entity.h"
#include "Animation.h"
#include "Collider.h"
#include "Player.h"

using namespace sf;

class Enemy : public Entity
{
public:
    Enemy(Texture* texture, Vector2u imageCount, float switchTime, int xPos, int yPos);
    ~Enemy();
    
    Vector2f GetEnemyPosition();
    Collider GetCollider() { return Collider(body); }
    
    void Update(float deltaTime, Player player);
    int GetDamage();
    void Destroy();
    bool ToDestroy();
    void LowerHealth(int n);
    int GetHealth();
    
private:
    float Speed;
    int Damage, Health;
    bool destroy;
    
    unsigned int row;
    
private:
     Animation animation;
};

#endif
