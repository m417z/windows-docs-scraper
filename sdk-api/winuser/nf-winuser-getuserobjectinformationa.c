BOOL GetUserObjectInformationA(
  [in]            HANDLE  hObj,
  [in]            int     nIndex,
  [out, optional] PVOID   pvInfo,
  [in]            DWORD   nLength,
  [out, optional] LPDWORD lpnLengthNeeded
);