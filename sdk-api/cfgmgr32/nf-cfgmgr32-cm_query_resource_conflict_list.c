CMAPI CONFIGRET CM_Query_Resource_Conflict_List(
  [out]          PCONFLICT_LIST pclConflictList,
  [in]           DEVINST        dnDevInst,
  [in]           RESOURCEID     ResourceID,
  [in]           PCVOID         ResourceData,
  [in]           ULONG          ResourceLen,
  [in]           ULONG          ulFlags,
  [in, optional] HMACHINE       hMachine
);