typedef struct tagDIBSECTION {
  BITMAP           dsBm;
  BITMAPINFOHEADER dsBmih;
  DWORD            dsBitfields[3];
  HANDLE           dshSection;
  DWORD            dsOffset;
} DIBSECTION, *LPDIBSECTION, *PDIBSECTION;