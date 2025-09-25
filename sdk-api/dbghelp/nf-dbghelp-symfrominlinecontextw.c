BOOL IMAGEAPI SymFromInlineContextW(
  [in]            HANDLE        hProcess,
  [in]            DWORD64       Address,
  [in]            ULONG         InlineContext,
  [out, optional] PDWORD64      Displacement,
  [in, out]       PSYMBOL_INFOW Symbol
);