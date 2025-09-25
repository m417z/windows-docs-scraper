typedef struct RILSETCALLFORWARDINGSTATUSPARAMS {
  DWORD                           dwExecutor;
  RILCALLFORWARDINGSETTINGSREASON dwReason;
  BOOL                            fAllClasses;
  DWORD                           dwInfoClasses;
  RILSERVICESETTINGSSTATUS        dwStatus;
} RILSETCALLFORWARDINGSTATUSPARAMS, *LPRILSETCALLFORWARDINGSTATUSPARAMS;