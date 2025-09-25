typedef struct _WKSTA_INFO_100 {
  DWORD wki100_platform_id;
  LMSTR wki100_computername;
  LMSTR wki100_langroup;
  DWORD wki100_ver_major;
  DWORD wki100_ver_minor;
} WKSTA_INFO_100, *PWKSTA_INFO_100, *LPWKSTA_INFO_100;