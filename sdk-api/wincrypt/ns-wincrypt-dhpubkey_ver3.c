typedef struct _PUBKEYVER3 {
  DWORD   magic;
  DWORD   bitlenP;
  DWORD   bitlenQ;
  DWORD   bitlenJ;
  DSSSEED DSSSeed;
} DHPUBKEY_VER3, DSSPUBKEY_VER3;