typedef struct tagEMRPOLYDRAW {
  EMR    emr;
  RECTL  rclBounds;
  DWORD  cptl;
  POINTL aptl[1];
  BYTE   abTypes[1];
} EMRPOLYDRAW, *PEMRPOLYDRAW;