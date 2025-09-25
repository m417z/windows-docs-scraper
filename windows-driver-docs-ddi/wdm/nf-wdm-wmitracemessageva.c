NTSTATUS WmiTraceMessageVa(
  [in] TRACELOGGER_HANDLE LoggerHandle,
  [in] ULONG              MessageFlags,
  [in] LPCGUID            MessageGuid,
  [in] USHORT             MessageNumber,
  [in] va_list            MessageArgList
);