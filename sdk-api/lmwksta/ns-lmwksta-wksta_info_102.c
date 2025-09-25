typedef struct _WKSTA_INFO_102 {
  DWORD wki102_platform_id;
  LMSTR wki102_computername;
  LMSTR wki102_langroup;
  DWORD wki102_ver_major;
  DWORD wki102_ver_minor;
  LMSTR wki102_lanroot;
  DWORD wki102_logged_on_users;
} WKSTA_INFO_102, *PWKSTA_INFO_102, *LPWKSTA_INFO_102;