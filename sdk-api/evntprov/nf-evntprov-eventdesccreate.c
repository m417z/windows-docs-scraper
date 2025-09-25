EVNTPROV_PFORCEINLINE VOID EventDescCreate(
  [out] PEVENT_DESCRIPTOR EventDescriptor,
  [in]  USHORT            Id,
  [in]  UCHAR             Version,
  [in]  UCHAR             Channel,
  [in]  UCHAR             Level,
  [in]  USHORT            Task,
  [in]  UCHAR             Opcode,
  [in]  ULONGLONG         Keyword
);