ULONG EVNTAPI EventWrite(
  [in]           REGHANDLE              RegHandle,
  [in]           PCEVENT_DESCRIPTOR     EventDescriptor,
  [in]           ULONG                  UserDataCount,
  [in, optional] PEVENT_DATA_DESCRIPTOR UserData
);