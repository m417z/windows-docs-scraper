typedef struct tagNMCUSTOMDRAWINFO {
  NMHDR     hdr;
  DWORD     dwDrawStage;
  HDC       hdc;
  RECT      rc;
  DWORD_PTR dwItemSpec;
  UINT      uItemState;
  LPARAM    lItemlParam;
} NMCUSTOMDRAW, *LPNMCUSTOMDRAW;