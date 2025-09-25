typedef struct RILSETCALLWAITINGSTATUSPARAMS {
  DWORD                    dwExecutor;
  BOOL                     fAllClasses;
  DWORD                    dwInfoClasses;
  RILSERVICESETTINGSSTATUS dwStatus;
} RILSETCALLWAITINGSTATUSPARAMS, *LPRILSETCALLWAITINGSTATUSPARAMS;