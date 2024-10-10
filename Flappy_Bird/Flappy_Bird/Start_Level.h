// Start_Level.h
#pragma once

#include <string>

class Start_Level {
protected:
    std::string level_name;

public:
    // Constructor to initialize the level name
    Start_Level(const std::string& name) : level_name(name) {}

    // Virtual destructor
    virtual ~Start_Level() {}

    // Pure virtual functions that must be implemented by derived classes
    virtual void init() = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
};
