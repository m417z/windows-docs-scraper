typedef struct tagEMRPOLYDRAW16 {
  EMR    emr;
  RECTL  rclBounds;
  DWORD  cpts;
  POINTS apts[1];
  BYTE   abTypes[1];
} EMRPOLYDRAW16, *PEMRPOLYDRAW16;