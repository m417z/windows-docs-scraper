typedef struct lineaddressstatus_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwNumInUse;
  DWORD dwNumActiveCalls;
  DWORD dwNumOnHoldCalls;
  DWORD dwNumOnHoldPendCalls;
  DWORD dwAddressFeatures;
  DWORD dwNumRingsNoAnswer;
  DWORD dwForwardNumEntries;
  DWORD dwForwardSize;
  DWORD dwForwardOffset;
  DWORD dwTerminalModesSize;
  DWORD dwTerminalModesOffset;
  DWORD dwDevSpecificSize;
  DWORD dwDevSpecificOffset;
} LINEADDRESSSTATUS, *LPLINEADDRESSSTATUS;