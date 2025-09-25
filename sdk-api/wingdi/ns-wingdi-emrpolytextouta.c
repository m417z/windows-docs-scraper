typedef struct tagEMRPOLYTEXTOUTA {
  EMR     emr;
  RECTL   rclBounds;
  DWORD   iGraphicsMode;
  FLOAT   exScale;
  FLOAT   eyScale;
  LONG    cStrings;
  EMRTEXT aemrtext[1];
} EMRPOLYTEXTOUTA, *PEMRPOLYTEXTOUTA, EMRPOLYTEXTOUTW, *PEMRPOLYTEXTOUTW;