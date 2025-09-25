typedef struct RILDMCONFIGINFOVALUE {
  DWORD               cbSize;
  RILDMCONFIGINFOTYPE dwType;
  BOOL                fValue;
  DWORD               dwValue;
  WCHAR               wszValue[256];
} RILDMCONFIGINFOVALUE, *LPRILDMCONFIGINFOVALUE;