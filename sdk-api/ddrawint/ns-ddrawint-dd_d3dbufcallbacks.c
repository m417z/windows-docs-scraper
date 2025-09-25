typedef struct _DD_D3DBUFCALLBACKS {
  DWORD                     dwSize;
  DWORD                     dwFlags;
  PDD_CANCREATESURFACE      CanCreateD3DBuffer;
  PDD_CREATESURFACE         CreateD3DBuffer;
  PDD_SURFCB_DESTROYSURFACE DestroyD3DBuffer;
  PDD_SURFCB_LOCK           LockD3DBuffer;
  PDD_SURFCB_UNLOCK         UnlockD3DBuffer;
} DD_D3DBUFCALLBACKS, *PDD_D3DBUFCALLBACKS;