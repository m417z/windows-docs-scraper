typedef struct _BDA_SCAN_STATE {
  PBDARESULT lResult;
  ULONG      ulSignalLock;
  ULONG      ulSecondsLeft;
  ULONG      ulCurrentFrequency;
} BDA_SCAN_STATE, *PBDA_SCAN_STATE;