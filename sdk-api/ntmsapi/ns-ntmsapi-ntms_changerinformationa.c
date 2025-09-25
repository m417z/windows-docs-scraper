typedef struct _NTMS_CHANGERINFORMATIONA {
  DWORD     Number;
  NTMS_GUID ChangerType;
  CHAR      szSerialNumber[NTMS_SERIALNUMBER_LENGTH];
  CHAR      szRevision[NTMS_REVISION_LENGTH];
  CHAR      szDeviceName[NTMS_DEVICENAME_LENGTH];
  WORD      ScsiPort;
  WORD      ScsiBus;
  WORD      ScsiTarget;
  WORD      ScsiLun;
  NTMS_GUID Library;
} NTMS_CHANGERINFORMATIONA;