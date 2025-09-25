struct RILUICCRECORDSTATUS {
  DWORD                 cbSize;
  DWORD                 dwParams;
  RILUICCRECORDTYPE     dwRecordType;
  DWORD                 dwItemCount;
  DWORD                 dwSize;
  RILUICCFILELOCKSTATUS fileLockStatus[MAXNUM_EFACCESSTYPES];
};