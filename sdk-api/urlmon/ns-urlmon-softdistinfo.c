typedef struct _tagSOFTDISTINFO {
  ULONG  cbSize;
  DWORD  dwFlags;
  DWORD  dwAdState;
  LPWSTR szTitle;
  LPWSTR szAbstract;
  LPWSTR szHREF;
  DWORD  dwInstalledVersionMS;
  DWORD  dwInstalledVersionLS;
  DWORD  dwUpdateVersionMS;
  DWORD  dwUpdateVersionLS;
  DWORD  dwAdvertisedVersionMS;
  DWORD  dwAdvertisedVersionLS;
  DWORD  dwReserved;
} SOFTDISTINFO, *LPSOFTDISTINFO;