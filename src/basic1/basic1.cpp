/* basic1.cpp
 * Copyright 2023-2024 Lunsheng Wang <lunsheng.wang@gmail.com>
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */
#include <string>
#include <memory>
#include "basic1.h"

int main(int argc, char* argv[])
{
    const std::string url {"https://gstreamer.freedesktop.org/data/media/sintel_trailer-480p.webm"};
    std::unique_ptr<tutorial::Player> player { std::make_unique<tutorial::Player1>(url) };

    player->init(argc, argv);
    player->play(url);

    return 0;
}