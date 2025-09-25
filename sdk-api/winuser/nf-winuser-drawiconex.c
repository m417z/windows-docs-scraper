BOOL DrawIconEx(
  [in]           HDC    hdc,
  [in]           int    xLeft,
  [in]           int    yTop,
  [in]           HICON  hIcon,
  [in]           int    cxWidth,
  [in]           int    cyWidth,
  [in]           UINT   istepIfAniCur,
  [in, optional] HBRUSH hbrFlickerFreeDraw,
  [in]           UINT   diFlags
);