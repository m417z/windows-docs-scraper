LPWSPADDRESSTOSTRING Lpwspaddresstostring;

INT Lpwspaddresstostring(
  [in]      LPSOCKADDR lpsaAddress,
  [in]      DWORD dwAddressLength,
  [in]      LPWSAPROTOCOL_INFOW lpProtocolInfo,
  [out]     LPWSTR lpszAddressString,
  [in, out] LPDWORD lpdwAddressStringLength,
  [out]     LPINT lpErrno
)
{...}