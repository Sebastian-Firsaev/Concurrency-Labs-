#ifndef EVENT_H
#define EVENT_H

class Event {
private:
    int eventId;

public:
    Event(int id); // Constructor declaration
    int consume(); // Method declaration
};

#endif // EVENT_H
