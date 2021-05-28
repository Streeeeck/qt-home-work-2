#ifndef TRACK_H
#define TRACK_H


class Track
{
    int first;
    int last;
public:
    Track(int _a, int _b);
    int getFirst() const;
    void setFirst(int value);
    int getLast() const;
    void setLast(int value);
};

#endif // TRACK_H
