TDHSTATUS TdhFormatProperty(
  [in]            PTRACE_EVENT_INFO EventInfo,
  [in, optional]  PEVENT_MAP_INFO   MapInfo,
  [in]            ULONG             PointerSize,
  [in]            USHORT            PropertyInType,
  [in]            USHORT            PropertyOutType,
  [in]            USHORT            PropertyLength,
  [in]            USHORT            UserDataLength,
  [in]            PBYTE             UserData,
  [in, out]       PULONG            BufferSize,
  [out, optional] PWCHAR            Buffer,
  [out]           PUSHORT           UserDataConsumed
);