typedef struct tagAXESLISTW {
  DWORD     axlReserved;
  DWORD     axlNumAxes;
  AXISINFOW axlAxisInfo[MM_MAX_NUMAXES];
} AXESLISTW, *PAXESLISTW, *LPAXESLISTW;