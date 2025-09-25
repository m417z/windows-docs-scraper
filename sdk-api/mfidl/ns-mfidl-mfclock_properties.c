typedef struct _MFCLOCK_PROPERTIES {
  unsigned __int64 qwCorrelationRate;
  GUID             guidClockId;
  DWORD            dwClockFlags;
  unsigned __int64 qwClockFrequency;
  DWORD            dwClockTolerance;
  DWORD            dwClockJitter;
} MFCLOCK_PROPERTIES;