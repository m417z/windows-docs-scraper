typedef struct tagNMMOUSE {
  NMHDR     hdr;
  DWORD_PTR dwItemSpec;
  DWORD_PTR dwItemData;
  POINT     pt;
  LPARAM    dwHitInfo;
} NMMOUSE, *LPNMMOUSE;