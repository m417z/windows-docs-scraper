BOOL CalculatePopupWindowPosition(
  [in]           const POINT *anchorPoint,
  [in]           const SIZE  *windowSize,
  [in]           UINT        flags,
  [in, optional] RECT        *excludeRect,
  [out]          RECT        *popupWindowPosition
);