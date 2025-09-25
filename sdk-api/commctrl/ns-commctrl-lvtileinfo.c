typedef struct tagLVTILEINFO {
  UINT  cbSize;
  int   iItem;
  UINT  cColumns;
  PUINT puColumns;
  int   *piColFmt;
} LVTILEINFO, *PLVTILEINFO;