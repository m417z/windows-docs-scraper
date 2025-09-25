typedef struct DD_PALETTECALLBACKS {
  DWORD                    dwSize;
  DWORD                    dwFlags;
  PDD_PALCB_DESTROYPALETTE DestroyPalette;
  PDD_PALCB_SETENTRIES     SetEntries;
} DD_PALETTECALLBACKS;