typedef struct _DDADDVPCAPTUREBUFF {
  HANDLE          hCapture;
  DWORD           dwFlags;
  PMDL            pMDL;
  PKEVENT         pKEvent;
  LPDDCAPBUFFINFO lpBuffInfo;
} DDADDVPCAPTUREBUFF, *LPDDADDVPCAPTUREBUFF;