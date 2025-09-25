typedef struct RILGETCALLBARRINGSTATUSPARAMS {
  DWORD                          dwExecutor;
  RILCALLBARRINGSTATUSPARAMSTYPE dwType;
  BOOL                           fAllClasses;
  DWORD                          dwInfoClasses;
} RILGETCALLBARRINGSTATUSPARAMS, *LPRILGETCALLBARRINGSTATUSPARAMS;