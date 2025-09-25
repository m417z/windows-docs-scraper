DSPARSE DWORD DsQuoteRdnValueA(
  [in]      DWORD cUnquotedRdnValueLength,
  [in]      LPCCH psUnquotedRdnValue,
  [in, out] DWORD *pcQuotedRdnValueLength,
  [out]     LPCH  psQuotedRdnValue
);