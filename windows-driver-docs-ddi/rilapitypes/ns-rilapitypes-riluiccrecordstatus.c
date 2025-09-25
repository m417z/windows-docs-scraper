typedef struct _RILUICCRECORDSTATUS {
  DWORD                                        cbSize;
  DWORD                                        dwParams;
  RILUICCRECORDTYPE                            dwRecordType;
  DWORD                                        dwItemCount;
  DWORD                                        dwSize;
  RILUICCFILELOCKSTATUS [MAXNUM_EFACCESSTYPES] fileLockStatus;
} RILUICCRECORDSTATUS, RILUICCRECORDSTATUS;