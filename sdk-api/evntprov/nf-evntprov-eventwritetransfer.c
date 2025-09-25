ULONG EVNTAPI EventWriteTransfer(
  [in]           REGHANDLE              RegHandle,
  [in]           PCEVENT_DESCRIPTOR     EventDescriptor,
  [in, optional] LPCGUID                ActivityId,
  [in, optional] LPCGUID                RelatedActivityId,
  [in]           ULONG                  UserDataCount,
  [in, optional] PEVENT_DATA_DESCRIPTOR UserData
);