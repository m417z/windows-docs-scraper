HRESULT RIL_SetCallForwardingStatus(
  HRIL                            hRil,
  LPVOID                          lpContext,
  DWORD                           dwExecutor,
  RILCALLFORWARDINGSETTINGSREASON dwReason,
  BOOL                            fAllClasses,
  DWORD                           dwInfoClasses,
  RILSERVICESETTINGSSTATUS        dwStatus
);