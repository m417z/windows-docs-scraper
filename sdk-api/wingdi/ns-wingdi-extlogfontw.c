typedef struct tagEXTLOGFONTW {
  LOGFONTW elfLogFont;
  WCHAR    elfFullName[LF_FULLFACESIZE];
  WCHAR    elfStyle[LF_FACESIZE];
  DWORD    elfVersion;
  DWORD    elfStyleSize;
  DWORD    elfMatch;
  DWORD    elfReserved;
  BYTE     elfVendorId[ELF_VENDOR_SIZE];
  DWORD    elfCulture;
  PANOSE   elfPanose;
} EXTLOGFONTW, *PEXTLOGFONTW, *NPEXTLOGFONTW, *LPEXTLOGFONTW;