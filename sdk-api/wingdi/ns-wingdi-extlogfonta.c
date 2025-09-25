typedef struct tagEXTLOGFONTA {
  LOGFONTA elfLogFont;
  BYTE     elfFullName[LF_FULLFACESIZE];
  BYTE     elfStyle[LF_FACESIZE];
  DWORD    elfVersion;
  DWORD    elfStyleSize;
  DWORD    elfMatch;
  DWORD    elfReserved;
  BYTE     elfVendorId[ELF_VENDOR_SIZE];
  DWORD    elfCulture;
  PANOSE   elfPanose;
} EXTLOGFONTA, *PEXTLOGFONTA, *NPEXTLOGFONTA, *LPEXTLOGFONTA;