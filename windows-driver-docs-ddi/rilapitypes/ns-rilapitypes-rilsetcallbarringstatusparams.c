typedef struct RILSETCALLBARRINGSTATUSPARAMS {
  DWORD                            dwExecutor;
  RILCALLBARRINGSTATUSPARAMSTYPE   dwType;
  BOOL                             fAllClasses;
  DWORD                            dwInfoClasses;
  BOOL                             fPassword;
  char                             szPassword[256];
  RILCALLBARRINGSTATUSPARAMSSTATUS dwStatus;
} RILSETCALLBARRINGSTATUSPARAMS, *LPRILSETCALLBARRINGSTATUSPARAMS;