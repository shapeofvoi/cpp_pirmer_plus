#ifndef TV_H_
#define TV_H_

class Tv {
    private:
        int state;  // on or off
        int volume;  // assumed to be digitized
        int maxchannel; // maximum number of channels
        int channel;  // current channel setting
        int mode;  // broadcast or cable 天线调节模式或有线电视
        int input;  // TV of DVD


    public:
        friend class Remote;  // Remote can access Tv private parts
        enum {Off, on};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};

        Tv(int s = Off, int mc = 125) : state(s), volume(5),
            maxchannel(mc), channel(2), mode(Cable), input(TV) {}
        void onoff() {state = (state == on) ? Off : on;}
        bool ison() const {return state == on; }
        bool volup();
        bool voldown();
        void chanup();
        void chandown();
        void set_mode() {mode = (mode == Antenna) ? Cable : Antenna; }
        void set_input() {input = (input == TV) ? DVD:TV;}
        void settings() const;  //display all settings

};

class Remote {
    private:
        int mode;  // controls TV or DVD
    public:
        Remote(int m = Tv::TV) : mode(m) {}
        bool volup(Tv& t) {return t.volup(); }
        bool voldown(Tv& t) {return t.voldown(); }
        void onoff(Tv& t) {t.onoff();}
        void chanup(Tv& t) {t.chanup();}
        void chandown(Tv& t) {t.chandown();}
        void set_chan(Tv& t,int c) {t.channel = c;} // 直接访问Tv成员
        void set_mode(Tv& t) {t.set_mode(); }
        void set_input(Tv& t) {t.set_input(); }

};

#endif