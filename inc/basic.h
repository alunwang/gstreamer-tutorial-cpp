/* basic.h
 * Copyright 2023-2024 Lunsheng Wang <lunsheng.wang@gmail.com>
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */
#include <string>

namespace tutorial {

class Player {
public:
    Player() {}
    virtual void init(int argc, char *argv[]) = 0;
    virtual void play(const std::string &url) = 0;
    virtual ~Player() {}

protected:
    std::string uri;
    GstElement *pipeline = nullptr;
    GstBus *bus = nullptr;
    GstMessage *msg = nullptr;
};

}