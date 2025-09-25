HRESULT RequestTerminal(
  [in]  BSTR               bstrTerminalClassGUID,
  [in]  long               lMediaType,
  [in]  TERMINAL_DIRECTION Direction,
  [out] ITTerminal         **ppTerminal
);