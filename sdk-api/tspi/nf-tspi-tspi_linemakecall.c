LONG TSPIAPI TSPI_lineMakeCall(
  DRV_REQUESTID          dwRequestID,
  HDRVLINE               hdLine,
  HTAPICALL              htCall,
  LPHDRVCALL             lphdCall,
  LPCWSTR                lpszDestAddress,
  DWORD                  dwCountryCode,
  LPLINECALLPARAMS const lpCallParams
);