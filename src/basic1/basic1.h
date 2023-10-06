/* basic1.h
 * Copyright 2023-2024 Lunsheng Wang <lunsheng.wang@gmail.com>
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */
#include <string>
#include <gst/gst.h>
#include "basic.h"

namespace tutorial {

class Player1 : public Player {
public:
    Player1(const std::string &uri_str)
    {
        uri = uri_str;
    }
    void init(int argc, char *argv[])
    {
        //Initialize Gstreamer
        gst_init(&argc, &argv);

        //Build the pipeline
        std::string str {"playbin uri="+uri};
        pipeline = gst_parse_launch(str.c_str(), NULL);
    }
    void play(const std::string &url)
    {
        //Start playing
        gst_element_set_state(pipeline, GST_STATE_PLAYING);

        //Wait until error or EOS
        bus = gst_element_get_bus(pipeline);
        msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
            (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_ERROR));
        if (GST_MESSAGE_TYPE(msg) == GST_MESSAGE_ERROR) {
            g_error("An error occured! Re-run it with the GST_DEBUG=*:WARN "
                "environment variable set for more details");
        }
    }
    ~Player1()
    {
        //Free resources
        gst_message_unref(msg);
        gst_object_unref(bus);
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);
    }

protected:
    std::string uri;
    GstElement *pipeline = nullptr;
    GstBus *bus = nullptr;
    GstMessage *msg = nullptr;
};

}