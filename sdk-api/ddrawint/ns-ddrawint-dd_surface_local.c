typedef struct _DD_SURFACE_LOCAL {
  PDD_SURFACE_GLOBAL lpGbl;
  DWORD              dwFlags;
  DDSCAPS            ddsCaps;
  ULONG_PTR          dwReserved1;
  union {
    DDCOLORKEY ddckCKSrcOverlay;
    DDCOLORKEY ddckCKSrcBlt;
  };
  union {
    DDCOLORKEY ddckCKDestOverlay;
    DDCOLORKEY ddckCKDestBlt;
  };
  PDD_SURFACE_MORE   lpSurfMore;
  PDD_ATTACHLIST     lpAttachList;
  PDD_ATTACHLIST     lpAttachListFrom;
  RECT               rcOverlaySrc;
} *PDD_SURFACE_LOCAL, DD_SURFACE_LOCAL;