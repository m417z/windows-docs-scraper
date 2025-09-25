typedef struct tagLITEM {
  UINT  mask;
  int   iLink;
  UINT  state;
  UINT  stateMask;
  WCHAR szID[MAX_LINKID_TEXT];
  WCHAR szUrl[L_MAX_URL_LENGTH];
} LITEM, *PLITEM;