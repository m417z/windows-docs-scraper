typedef struct tagNMVIEWCHANGE {
  NMHDR nmhdr;
  DWORD dwOldView;
  DWORD dwNewView;
} NMVIEWCHANGE, *LPNMVIEWCHANGE;