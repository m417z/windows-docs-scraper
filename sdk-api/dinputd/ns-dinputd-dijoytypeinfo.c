typedef struct DIJOYTYPEINFO {
  DWORD            dwSize;
  JOYREGHWSETTINGS hws;
  CLSID            clsidConfig;
  WCHAR            wszDisplayName[MAX_JOYSTRING];
  WCHAR            wszCallout[MAX_JOYSTICKOEMVXDNAME];
  WCHAR            wszHardwareId[MAX_JOYSTRING];
  DWORD            dwFlags1;
  DWORD            dwFlags2;
  WCHAR            wszMapFile[MAX_JOYSTRING];
} DIJOYTYPEINFO, *LPDIJOYTYPEINFO;