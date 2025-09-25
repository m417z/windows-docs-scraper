typedef struct _NTMS_CHANGERINFORMATIONW {
  DWORD     Number;
  NTMS_GUID ChangerType;
  WCHAR     szSerialNumber[NTMS_SERIALNUMBER_LENGTH];
  WCHAR     szRevision[NTMS_REVISION_LENGTH];
  WCHAR     szDeviceName[NTMS_DEVICENAME_LENGTH];
  WORD      ScsiPort;
  WORD      ScsiBus;
  WORD      ScsiTarget;
  WORD      ScsiLun;
  NTMS_GUID Library;
} NTMS_CHANGERINFORMATIONW;