HRESULT GetDumpFileWide(
  [in]            ULONG    Index,
  [out, optional] PWSTR    Buffer,
  [in]            ULONG    BufferSize,
  [out, optional] PULONG   NameSize,
  [out, optional] PULONG64 Handle,
  [out]           PULONG   Type
);