DSPARSE DWORD DsQuoteRdnValueW(
  [in]      DWORD  cUnquotedRdnValueLength,
  [in]      LPCWCH psUnquotedRdnValue,
  [in, out] DWORD  *pcQuotedRdnValueLength,
  [out]     LPWCH  psQuotedRdnValue
);