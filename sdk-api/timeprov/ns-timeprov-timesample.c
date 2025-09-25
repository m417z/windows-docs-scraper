typedef struct TimeSample {
  DWORD            dwSize;
  DWORD            dwRefid;
  signed __int64   toOffset;
  signed __int64   toDelay;
  unsigned __int64 tpDispersion;
  unsigned __int64 nSysTickCount;
  signed __int64   nSysPhaseOffset;
  BYTE             nLeapFlags;
  BYTE             nStratum;
  DWORD            dwTSFlags;
  WCHAR            wszUniqueName[256];
} TimeSample;