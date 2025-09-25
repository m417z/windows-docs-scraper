HRESULT RIL_SetCallBarringStatus(
  HRIL                             hRil,
  LPVOID                           lpContext,
  DWORD                            dwExecutor,
  RILCALLBARRINGSTATUSPARAMSTYPE   dwType,
  BOOL                             fAllClasses,
  DWORD                            dwInfoClasses,
  LPCSTR                           lpszPassword,
  RILCALLBARRINGSTATUSPARAMSSTATUS dwStatus
);