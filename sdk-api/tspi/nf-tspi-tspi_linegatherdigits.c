LONG TSPIAPI TSPI_lineGatherDigits(
  HDRVCALL hdCall,
  DWORD    dwEndToEndID,
  DWORD    dwDigitModes,
  LPWSTR   lpsDigits,
  DWORD    dwNumDigits,
  LPCWSTR  lpszTerminationDigits,
  DWORD    dwFirstDigitTimeout,
  DWORD    dwInterDigitTimeout
);