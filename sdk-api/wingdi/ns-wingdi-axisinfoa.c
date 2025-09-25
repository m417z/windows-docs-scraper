typedef struct tagAXISINFOA {
  LONG axMinValue;
  LONG axMaxValue;
  BYTE axAxisName[MM_MAX_AXES_NAMELEN];
} AXISINFOA, *PAXISINFOA, *LPAXISINFOA;