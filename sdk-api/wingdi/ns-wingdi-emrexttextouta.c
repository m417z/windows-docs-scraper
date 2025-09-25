typedef struct tagEMREXTTEXTOUTA {
  EMR     emr;
  RECTL   rclBounds;
  DWORD   iGraphicsMode;
  FLOAT   exScale;
  FLOAT   eyScale;
  EMRTEXT emrtext;
} EMREXTTEXTOUTA, *PEMREXTTEXTOUTA, EMREXTTEXTOUTW, *PEMREXTTEXTOUTW;