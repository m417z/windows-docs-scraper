typedef struct _WKSTA_INFO_101 {
  DWORD wki101_platform_id;
  LMSTR wki101_computername;
  LMSTR wki101_langroup;
  DWORD wki101_ver_major;
  DWORD wki101_ver_minor;
  LMSTR wki101_lanroot;
} WKSTA_INFO_101, *PWKSTA_INFO_101, *LPWKSTA_INFO_101;