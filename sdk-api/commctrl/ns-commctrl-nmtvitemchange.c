typedef struct tagTVITEMCHANGE {
  NMHDR     hdr;
  UINT      uChanged;
  HTREEITEM hItem;
  UINT      uStateNew;
  UINT      uStateOld;
  LPARAM    lParam;
} NMTVITEMCHANGE;