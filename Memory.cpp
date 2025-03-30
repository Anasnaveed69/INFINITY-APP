#include "Memory.h"
#include <iostream>

Memory::Memory(Post* refPost, const char* memoryText)
    : referencePost(refPost), nextMemory(nullptr) {
    text = new char[strlen(memoryText) + 1];
    strcpy(text, memoryText);
}

Memory::~Memory() {
    delete[] text;
}

void Memory::setText(const char* newText) {
    delete[] text;
    text = new char[strlen(newText) + 1];
    strcpy(text, newText);
}

const char* Memory::getText() const {
    return text;
}

Memory* Memory::getNextMemory() const {
    return nextMemory;
}

void Memory::addMemory(Memory* newMemory) {
    if (!nextMemory) {
        nextMemory = newMemory;
    }
    else {
        Memory* current = nextMemory;
        while (current->getNextMemory()) {
            current = current->getNextMemory();
        }
        current->nextMemory = newMemory;
    }
}

