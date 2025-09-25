typedef struct _MAPTABLE {
  DWORD     dwSize;
  DWORD     dwGlyphNum;
  TRANSDATA Trans[1];
} MAPTABLE, *PMAPTABLE;