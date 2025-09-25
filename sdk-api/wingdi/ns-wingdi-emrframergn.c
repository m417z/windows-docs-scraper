typedef struct tagEMRFRAMERGN {
  EMR   emr;
  RECTL rclBounds;
  DWORD cbRgnData;
  DWORD ihBrush;
  SIZEL szlStroke;
  BYTE  RgnData[1];
} EMRFRAMERGN, *PEMRFRAMERGN;