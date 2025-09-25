BOOL GetUserObjectSecurity(
  [in]                HANDLE                hObj,
  [in]                PSECURITY_INFORMATION pSIRequested,
  [in, out, optional] PSECURITY_DESCRIPTOR  pSID,
  [in]                DWORD                 nLength,
  [out]               LPDWORD               lpnLengthNeeded
);