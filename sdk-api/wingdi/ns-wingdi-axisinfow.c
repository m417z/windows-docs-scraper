typedef struct tagAXISINFOW {
  LONG  axMinValue;
  LONG  axMaxValue;
  WCHAR axAxisName[MM_MAX_AXES_NAMELEN];
} AXISINFOW, *PAXISINFOW, *LPAXISINFOW;