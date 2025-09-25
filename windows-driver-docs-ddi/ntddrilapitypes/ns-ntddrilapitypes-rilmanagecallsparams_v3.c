typedef struct RILMANAGECALLSPARAMS_V3 {
  DWORD                      dwExecutor;
  RILMANAGECALLPARAMSCOMMAND dwCommand;
  DWORD                      dwID;
  BOOL                       fHasOfferAnswer;
  RILCALLMEDIAOFFERANSWERSET rcmOfferAnswer;
  RILADDRESS                 raAddress;
} RILMANAGECALLSPARAMS_V3, *LPRILMANAGECALLSPARAMS_V3;