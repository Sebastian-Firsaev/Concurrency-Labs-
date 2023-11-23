#include "Event.h"

// Implementation of the constructor
Event::Event(int id) : eventId(id) {}

// Implementation of the consume method
int Event::consume() {
    return eventId; // Return the event ID
}
