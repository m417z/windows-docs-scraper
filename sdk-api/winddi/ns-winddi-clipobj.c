typedef struct _CLIPOBJ {
  ULONG iUniq;
  RECTL rclBounds;
  BYTE  iDComplexity;
  BYTE  iFComplexity;
  BYTE  iMode;
  BYTE  fjOptions;
} CLIPOBJ;