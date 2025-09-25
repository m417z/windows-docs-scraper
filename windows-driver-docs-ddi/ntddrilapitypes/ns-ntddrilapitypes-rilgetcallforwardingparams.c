typedef struct RILGETCALLFORWARDINGPARAMS {
  DWORD                           dwExecutor;
  RILCALLFORWARDINGSETTINGSREASON dwReason;
  BOOL                            fAllClasses;
  DWORD                           dwInfoClasses;
} RILGETCALLFORWARDINGPARAMS, *LPRILGETCALLFORWARDINGPARAMS;