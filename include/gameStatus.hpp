class gameStatus
{
public:

    bool firstMenu=1;
    bool firstLoad=0;
    bool game=0;

    bool isMenu=0;
    bool isSaving=0;
    bool win=0;

    int figure_x = 0;
    int figure_y = 0;
    int target_x = 0;
    int target_y = 0;
    bool ruch=1;
    int zakazaneX;
    int zakazaneY;

    int tura;
    int nrTura=1;
    int oldTura =1;

    bool lostFocus=0;
    bool mouseButtonFromPrev=0;

    int posuniecieX = 0;
    int posuniecieY = 0;

    bool click=0;
    float scale;

    void adjustView();
};


