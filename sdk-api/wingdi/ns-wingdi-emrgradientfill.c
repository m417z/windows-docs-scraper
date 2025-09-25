typedef struct tagEMRGRADIENTFILL {
  EMR       emr;
  RECTL     rclBounds;
  DWORD     nVer;
  DWORD     nTri;
  ULONG     ulMode;
  TRIVERTEX Ver[1];
} EMRGRADIENTFILL, *PEMRGRADIENTFILL;