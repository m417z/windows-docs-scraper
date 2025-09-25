HRESULT GetPseudoDescription(
  [in]            ULONG    Register,
  [out, optional] PSTR     NameBuffer,
  [in]            ULONG    NameBufferSize,
  [out, optional] PULONG   NameSize,
  [out, optional] PULONG64 TypeModule,
  [out, optional] PULONG   TypeId
);