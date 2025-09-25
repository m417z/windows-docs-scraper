HRESULT CreateTerminal(
  [in]  BSTR               pTerminalClass,
  [in]  long               lMediaType,
  [in]  TERMINAL_DIRECTION Direction,
  [out] ITTerminal         **ppTerminal
);