typedef struct tagAXESLISTA {
  DWORD     axlReserved;
  DWORD     axlNumAxes;
  AXISINFOA axlAxisInfo[MM_MAX_NUMAXES];
} AXESLISTA, *PAXESLISTA, *LPAXESLISTA;