typedef struct _GROUP_POLICY_OBJECTA {
  DWORD                        dwOptions;
  DWORD                        dwVersion;
  LPSTR                        lpDSPath;
  LPSTR                        lpFileSysPath;
  LPSTR                        lpDisplayName;
  CHAR                         szGPOName[50];
  GPO_LINK                     GPOLink;
  LPARAM                       lParam;
  struct _GROUP_POLICY_OBJECTA *pNext;
  struct _GROUP_POLICY_OBJECTA *pPrev;
  LPSTR                        lpExtensions;
  LPARAM                       lParam2;
  LPSTR                        lpLink;
} GROUP_POLICY_OBJECTA, *PGROUP_POLICY_OBJECTA;