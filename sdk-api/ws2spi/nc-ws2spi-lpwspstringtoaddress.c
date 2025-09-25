LPWSPSTRINGTOADDRESS Lpwspstringtoaddress;

INT Lpwspstringtoaddress(
  [in]      LPWSTR AddressString,
  [in]      INT AddressFamily,
  [in]      LPWSAPROTOCOL_INFOW lpProtocolInfo,
  [out]     LPSOCKADDR lpAddress,
  [in, out] LPINT lpAddressLength,
  [out]     LPINT lpErrno
)
{...}