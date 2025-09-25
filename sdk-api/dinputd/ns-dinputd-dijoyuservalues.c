typedef struct DIJOYUSERVALUES {
  DWORD            dwSize;
  JOYREGUSERVALUES ruv;
  WCHAR            wszGlobalDriver[MAX_JOYSTRING];
  WCHAR            wszGameportEmulator[MAX_JOYSTRING];
} DIJOYUSERVALUES, *LPDIJOYUSERVALUES;