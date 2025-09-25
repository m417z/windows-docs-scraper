typedef struct tagMSLLHOOKSTRUCT {
  POINT     pt;
  DWORD     mouseData;
  DWORD     flags;
  DWORD     time;
  ULONG_PTR dwExtraInfo;
} MSLLHOOKSTRUCT, *LPMSLLHOOKSTRUCT, *PMSLLHOOKSTRUCT;