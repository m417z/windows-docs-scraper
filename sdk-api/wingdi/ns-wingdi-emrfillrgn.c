typedef struct tagEMRFILLRGN {
  EMR   emr;
  RECTL rclBounds;
  DWORD cbRgnData;
  DWORD ihBrush;
  BYTE  RgnData[1];
} EMRFILLRGN, *PEMRFILLRGN;