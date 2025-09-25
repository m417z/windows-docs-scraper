typedef struct _DDTRANSFERININFO {
  LPDDSURFACEDATA lpSurfaceData;
  DWORD           dwStartLine;
  DWORD           dwEndLine;
  ULONG_PTR       dwTransferID;
  DWORD           dwTransferFlags;
  PMDL            lpDestMDL;
} DDTRANSFERININFO, *PDDTRANSFERININFO;