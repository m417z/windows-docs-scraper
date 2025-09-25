typedef struct tagRootCauseInfo {
  LPWSTR       pwszDescription;
  GUID         rootCauseID;
  DWORD        rootCauseFlags;
  GUID         networkInterfaceID;
  RepairInfoEx *pRepairs;
  USHORT       repairCount;
} RootCauseInfo, *PRootCauseInfo;