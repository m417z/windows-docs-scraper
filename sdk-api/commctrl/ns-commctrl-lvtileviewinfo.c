typedef struct tagLVTILEVIEWINFO {
  UINT  cbSize;
  DWORD dwMask;
  DWORD dwFlags;
  SIZE  sizeTile;
  int   cLines;
  RECT  rcLabelMargin;
} LVTILEVIEWINFO, *PLVTILEVIEWINFO;