NTSTATUS EtwWriteEx(
  [in]           REGHANDLE              RegHandle,
  [in]           PCEVENT_DESCRIPTOR     EventDescriptor,
  [in]           ULONG64                Filter,
  [in]           ULONG                  Flags,
  [in, optional] LPCGUID                ActivityId,
  [in, optional] LPCGUID                RelatedActivityId,
  [in]           ULONG                  UserDataCount,
  [in, optional] PEVENT_DATA_DESCRIPTOR UserData
);