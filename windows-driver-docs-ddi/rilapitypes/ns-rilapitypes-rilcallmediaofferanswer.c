typedef struct RILCALLMEDIAOFFERANSWER {
  DWORD                   cbSize;
  DWORD                   dwParams;
  RILCALLMEDIAID          stID;
  BOOL                    fChange;
  RILCALLMEDIAOFFERACTION dwMediaAction;
  RILCALLMEDIASTATE       stOldState;
  RILCALLMEDIASTATE       stNewState;
} RILCALLMEDIAOFFERANSWER, *LPRILCALLMEDIAOFFERANSWER;