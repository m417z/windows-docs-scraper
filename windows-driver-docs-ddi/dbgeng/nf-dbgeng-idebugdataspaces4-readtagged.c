HRESULT ReadTagged(
  [in]            LPGUID Tag,
  [in]            ULONG  Offset,
  [out, optional] PVOID  Buffer,
  [in]            ULONG  BufferSize,
  [out, optional] PULONG TotalSize
);