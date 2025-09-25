HRESULT GetModuleByModuleName2Wide(
  [in]            PCWSTR   Name,
  [in]            ULONG    StartIndex,
  [in]            ULONG    Flags,
  [out, optional] PULONG   Index,
  [out, optional] PULONG64 Base
);