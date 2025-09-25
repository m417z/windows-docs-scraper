typedef struct _NTMS_IEPORTINFORMATION {
  DWORD     Number;
  DWORD     Content;
  DWORD     Position;
  WORD      MaxExtendSecs;
  NTMS_GUID Library;
} NTMS_IEPORTINFORMATION;