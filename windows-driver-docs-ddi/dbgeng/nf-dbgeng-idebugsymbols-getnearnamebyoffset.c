HRESULT GetNearNameByOffset(
  [in]            ULONG64  Offset,
  [in]            LONG     Delta,
  [out, optional] PSTR     NameBuffer,
  [in]            ULONG    NameBufferSize,
  [out, optional] PULONG   NameSize,
  [out, optional] PULONG64 Displacement
);