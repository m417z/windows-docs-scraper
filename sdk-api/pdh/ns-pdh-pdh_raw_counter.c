typedef struct _PDH_RAW_COUNTER {
  DWORD    CStatus;
  FILETIME TimeStamp;
  LONGLONG FirstValue;
  LONGLONG SecondValue;
  DWORD    MultiCount;
} PDH_RAW_COUNTER, *PPDH_RAW_COUNTER;