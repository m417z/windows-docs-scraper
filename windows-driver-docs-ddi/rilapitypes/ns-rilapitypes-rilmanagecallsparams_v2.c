typedef struct RILMANAGECALLSPARAMS_V2 {
  DWORD                      dwExecutor;
  RILMANAGECALLPARAMSCOMMAND dwCommand;
  DWORD                      dwID;
  BOOL                       fHasOfferAnswer;
  RILCALLMEDIAOFFERANSWERSET rcmOfferAnswer;
} RILMANAGECALLSPARAMS_V2, *LPRILMANAGECALLSPARAMS_V2;