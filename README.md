ThreadComms
==========

A quick post office system for intra-thread communications in a thread-safe way
that allows you to register an address for a thread and then send and receive
arbitrary buffers that can be casted to their appropriate types and/ or
accessed raw.

Example application creates 10 threads that will run sending random other
threads messages until they have received 10 messages themselves, at which
point they will exist and be joined.

Some portions of the class have been left purposely incomplete for users to
fill in if they so choose.

Twitch?
=======

Yeah, they have a programming section and everything, so I figured I'd lend
some knowledge to programming broadcasts that take the form of a video
tutorial. In the broadcasts I go through what I am creating, why I am making
the decisions I am (and programming the items in a given way) as well as some
of the common pit falls that people just starting out run in to.

If you are interested in viewing a broadcast at some point, feel free to drop
by! [My Twitch Channel](https://www.twitch.tv/betawar1305).

License
=======

GPLv2
