typedef struct {
  KSEVENTDATA  EventData;
  ULONG        StartFrequency;
  ULONG        EndFrequency;
  BDA_LockType LockRequested;
} KSEVENTDATA_BDA_RF_TUNER_SCAN_S, *PKSEVENTDATA_BDA_RF_TUNER_SCAN_S;