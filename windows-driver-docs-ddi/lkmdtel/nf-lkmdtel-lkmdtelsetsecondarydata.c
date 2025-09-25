NTSTATUS LkmdTelSetSecondaryData(
  HANDLE  TelemetryHandle,
  LPCGUID SecondaryDataGuid,
  ULONG   SecondaryDataSize,
  PVOID   SecondaryDataBuffer
);