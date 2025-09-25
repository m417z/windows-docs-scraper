NTSTATUS EtwWrite(
  [in]           REGHANDLE              RegHandle,
  [in]           PCEVENT_DESCRIPTOR     EventDescriptor,
  [in, optional] LPCGUID                ActivityId,
  [in]           ULONG                  UserDataCount,
  [in, optional] PEVENT_DATA_DESCRIPTOR UserData
);