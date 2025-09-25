typedef struct _PRIVKEYVER3 {
  DWORD   magic;
  DWORD   bitlenP;
  DWORD   bitlenQ;
  DWORD   bitlenJ;
  DWORD   bitlenX;
  DSSSEED DSSSeed;
} DHPRIVKEY_VER3, DSSPRIVKEY_VER3;