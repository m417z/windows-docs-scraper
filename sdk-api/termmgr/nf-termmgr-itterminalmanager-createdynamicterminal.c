HRESULT CreateDynamicTerminal(
  [in]  IUnknown           *pOuterUnknown,
  [in]  IID                iidTerminalClass,
  [in]  DWORD              dwMediaType,
  [in]  TERMINAL_DIRECTION Direction,
  [in]  MSP_HANDLE         htAddress,
  [out] ITTerminal         **ppTerminal
);