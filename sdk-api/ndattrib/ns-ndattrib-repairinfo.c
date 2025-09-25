typedef struct tagRepairInfo {
  GUID         guid;
  LPWSTR       pwszClassName;
  LPWSTR       pwszDescription;
  DWORD        sidType;
  long         cost;
  ULONG        flags;
  REPAIR_SCOPE scope;
  REPAIR_RISK  risk;
  UiInfo       UiInfo;
  int          rootCauseIndex;
} RepairInfo, *PRepairInfo;