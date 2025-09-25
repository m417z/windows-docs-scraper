LONG TSPIAPI TSPI_lineSetTerminal(
  DRV_REQUESTID dwRequestID,
  HDRVLINE      hdLine,
  DWORD         dwAddressID,
  HDRVCALL      hdCall,
  DWORD         dwSelect,
  DWORD         dwTerminalModes,
  DWORD         dwTerminalID,
  DWORD         bEnable
);