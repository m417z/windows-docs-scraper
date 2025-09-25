typedef struct _D3DKMT_PRESENT_RGNS {
  UINT                   DirtyRectCount;
  const RECT             *pDirtyRects;
  UINT                   MoveRectCount;
  const D3DKMT_MOVE_RECT *pMoveRects;
} D3DKMT_PRESENT_RGNS;