HRESULT GetPseudoDescriptionWide(
  [in]            ULONG    Register,
  [out, optional] PWSTR    NameBuffer,
  [in]            ULONG    NameBufferSize,
  [out, optional] PULONG   NameSize,
  [out, optional] PULONG64 TypeModule,
  [out, optional] PULONG   TypeId
);