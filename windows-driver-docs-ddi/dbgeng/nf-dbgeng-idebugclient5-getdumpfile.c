HRESULT GetDumpFile(
  [in]            ULONG    Index,
  [out, optional] PSTR     Buffer,
  [in]            ULONG    BufferSize,
  [out, optional] PULONG   NameSize,
  [out, optional] PULONG64 Handle,
  [out]           PULONG   Type
);