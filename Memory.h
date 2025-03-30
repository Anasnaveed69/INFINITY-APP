#pragma once
#include "Post.h" // Include Post.h for Post class



class Memory {
private:
    char* text;
    Post* referencePost;
    Memory* nextMemory;

public:
    Memory(Post* refPost, const char* memoryText);
    ~Memory();

    void setText(const char* newText);
    const char* getText() const;
    Memory* getNextMemory() const;

    void addMemory(Memory* newMemory);
};
