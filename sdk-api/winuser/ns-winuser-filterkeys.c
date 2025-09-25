typedef struct tagFILTERKEYS {
  UINT  cbSize;
  DWORD dwFlags;
  DWORD iWaitMSec;
  DWORD iDelayMSec;
  DWORD iRepeatMSec;
  DWORD iBounceMSec;
} FILTERKEYS, *LPFILTERKEYS;