typedef struct tagNMTVASYNCDRAW {
  NMHDR               hdr;
  IMAGELISTDRAWPARAMS *pimldp;
  HRESULT             hr;
  HTREEITEM           hItem;
  LPARAM              lParam;
  DWORD               dwRetFlags;
  int                 iRetImageIndex;
} NMTVASYNCDRAW;