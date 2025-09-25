typedef struct _DD_SURFACE_MORE {
  DWORD               dwMipMapCount;
  PDD_VIDEOPORT_LOCAL lpVideoPort;
  DWORD               dwOverlayFlags;
  DDSCAPSEX           ddsCapsEx;
  DWORD               dwSurfaceHandle;
} *PDD_SURFACE_MORE, DD_SURFACE_MORE;