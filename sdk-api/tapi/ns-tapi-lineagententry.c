typedef struct lineagententry_tag {
  HAGENT hAgent;
  DWORD  dwNameSize;
  DWORD  dwNameOffset;
  DWORD  dwIDSize;
  DWORD  dwIDOffset;
  DWORD  dwPINSize;
  DWORD  dwPINOffset;
} LINEAGENTENTRY, *LPLINEAGENTENTRY;