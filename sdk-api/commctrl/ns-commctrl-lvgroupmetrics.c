typedef struct tagLVGROUPMETRICS {
  UINT     cbSize;
  UINT     mask;
  UINT     Left;
  UINT     Top;
  UINT     Right;
  UINT     Bottom;
  COLORREF crLeft;
  COLORREF crTop;
  COLORREF crRight;
  COLORREF crBottom;
  COLORREF crHeader;
  COLORREF crFooter;
} LVGROUPMETRICS, *PLVGROUPMETRICS;