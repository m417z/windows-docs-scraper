typedef struct RILCARDAPPADDED {
  DWORD          cbSize;
  DWORD          dwParams;
  DWORD          dwSlotIndex;
  RILUICCAPPINFO rilUiccAppInfo;
} RILCARDAPPADDED, *LPRILCARDAPPADDED;