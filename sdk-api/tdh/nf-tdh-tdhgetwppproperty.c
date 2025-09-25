TDHSTATUS TdhGetWppProperty(
  [in]      TDH_HANDLE    Handle,
  [in]      PEVENT_RECORD EventRecord,
  [in]      PWSTR         PropertyName,
  [in, out] PULONG        BufferSize,
  [out]     PBYTE         Buffer
);