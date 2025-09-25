HRESULT GetNearNameByOffsetWide(
  [in]            ULONG64  Offset,
  [in]            LONG     Delta,
  [out, optional] PWSTR    NameBuffer,
  [in]            ULONG    NameBufferSize,
  [out, optional] PULONG   NameSize,
  [out, optional] PULONG64 Displacement
);