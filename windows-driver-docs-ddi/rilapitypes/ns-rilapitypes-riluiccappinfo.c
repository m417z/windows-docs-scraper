typedef struct RILUICCAPPINFO {
  DWORD          cbSize;
  DWORD          dwParams;
  HUICCAPP       hUiccApp;
  RILUICCAPPTYPE dwUiccAppType;
  DWORD          dwAppIdLength;
  BYTE           bAppId[32];
  DWORD          dwAppNameLength;
  char           cszAppName[256];
  DWORD          dwNumPins;
  BYTE           bPinRef[8];
} RILUICCAPPINFO, *LPRILUICCAPPINFO;