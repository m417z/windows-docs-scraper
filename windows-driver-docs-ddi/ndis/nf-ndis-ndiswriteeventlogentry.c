NDIS_STATUS NdisWriteEventLogEntry(
  [in]           PVOID       LogHandle,
  [in]           NDIS_STATUS EventCode,
  [in]           ULONG       UniqueEventValue,
  [in]           USHORT      NumStrings,
  [in, optional] PVOID       StringsList,
  [in]           ULONG       DataSize,
  [in, optional] PVOID       Data
);