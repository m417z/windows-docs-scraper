typedef struct RILUICCCARDINFO {
  DWORD          cbSize;
  DWORD          dwParams;
  BOOL           fIsVirtualCard;
  BYTE           IccId[10];
  DWORD          dwNumApps;
  RILUICCAPPINFO AppInfo[1];
} RILUICCCARDINFO, *LPRILUICCCARDINFO;