typedef struct _PERF_DATA_BLOCK {
  WCHAR         Signature[4];
  DWORD         LittleEndian;
  DWORD         Version;
  DWORD         Revision;
  DWORD         TotalByteLength;
  DWORD         HeaderLength;
  DWORD         NumObjectTypes;
  LONG          DefaultObject;
  SYSTEMTIME    SystemTime;
  LARGE_INTEGER PerfTime;
  LARGE_INTEGER PerfFreq;
  LARGE_INTEGER PerfTime100nSec;
  DWORD         SystemNameLength;
  DWORD         SystemNameOffset;
} PERF_DATA_BLOCK, *PPERF_DATA_BLOCK;