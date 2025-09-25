typedef struct RILMANAGECALLSPARAMS_V4 {
  DWORD                      dwExecutor;
  RILMANAGECALLPARAMSCOMMAND dwCommand;
  DWORD                      dwID;
  BOOL                       fHasOfferAnswer;
  RILCALLMEDIAOFFERANSWERSET rcmOfferAnswer;
  RILADDRESS                 raAddress;
  RILCALLRTT                 stRTTInfo;
} RILMANAGECALLSPARAMS_V4, *LPRILMANAGECALLSPARAMS_V4, RILMANAGECALLSPARAMS, *LPRILMANAGECALLSPARAMS;