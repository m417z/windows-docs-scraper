DWORD NPLogonNotify(
  [in]  PLUID   lpLogonId,
  [in]  LPCWSTR lpAuthentInfoType,
  [in]  LPVOID  lpAuthentInfo,
  [in]  LPCWSTR lpPreviousAuthentInfoType,
  [in]  LPVOID  lpPreviousAuthentInfo,
  [in]  LPWSTR  lpStationName,
  [in]  LPVOID  StationHandle,
  [out] LPWSTR  *lpLogonScript
);