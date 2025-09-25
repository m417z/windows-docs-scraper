typedef struct RILDIALPARAMS_V2 {
  DWORD                      dwExecutor;
  RILADDRESS                 raAddress;
  DWORD                      dwOptions;
  RILCALLTYPE                dwType;
  BOOL                       fHasMediaOffer;
  RILCALLMEDIAOFFERANSWERSET rcmMediaOffer;
} RILDIALPARAMS_V2, *LPRILDIALPARAMS_V2, RILDIALPARAMS, *LPRILDIALPARAMS;