typedef struct _DXGK_GDIARG_STRETCHBLT {
  [in] RECT  SrcRect;
  [in] RECT  DstRect;
  [in] UINT  DstAllocationIndex;
  [in] UINT  SrcAllocationIndex;
       UINT  NumSubRects;
  [in] RECT  *pSubRects;
  union {
    struct {
      UINT Mode : 16;
      UINT MirrorX : 1;
      UINT MirrorY : 1;
    };
    [in] UINT Flags;
  };
  [in] UINT  SrcPitch;
} DXGK_GDIARG_STRETCHBLT;