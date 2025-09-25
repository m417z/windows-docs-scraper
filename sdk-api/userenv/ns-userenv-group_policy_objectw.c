typedef struct _GROUP_POLICY_OBJECTW {
  DWORD                        dwOptions;
  DWORD                        dwVersion;
  LPWSTR                       lpDSPath;
  LPWSTR                       lpFileSysPath;
  LPWSTR                       lpDisplayName;
  WCHAR                        szGPOName[50];
  GPO_LINK                     GPOLink;
  LPARAM                       lParam;
  struct _GROUP_POLICY_OBJECTW *pNext;
  struct _GROUP_POLICY_OBJECTW *pPrev;
  LPWSTR                       lpExtensions;
  LPARAM                       lParam2;
  LPWSTR                       lpLink;
} GROUP_POLICY_OBJECTW, *PGROUP_POLICY_OBJECTW;