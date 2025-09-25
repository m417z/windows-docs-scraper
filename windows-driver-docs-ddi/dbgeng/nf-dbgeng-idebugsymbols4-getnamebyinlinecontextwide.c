HRESULT GetNameByInlineContextWide(
  [in]            ULONG64  Offset,
  [in]            ULONG    InlineContext,
  [out]           PWSTR    NameBuffer,
  [in]            ULONG    NameBufferSize,
  [out, optional] PULONG   NameSize,
  [out, optional] PULONG64 Displacement
);