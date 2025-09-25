typedef struct DIJOYCONFIG {
  DWORD          dwSize;
  GUID           guidInstance;
  JOYREGHWCONFIG hwc;
  DWORD          dwGain;
  WCHAR          wszType[MAX_JOYSTRING];
  WCHAR          wszCallout[MAX_JOYSTRING];
  GUID           guidGameport;
} DIJOYCONFIG, *LPDIJOYCONFIG;