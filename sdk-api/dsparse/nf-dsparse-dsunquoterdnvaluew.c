DSPARSE DWORD DsUnquoteRdnValueW(
  [in]      DWORD  cQuotedRdnValueLength,
  [in]      LPCWCH psQuotedRdnValue,
  [in, out] DWORD  *pcUnquotedRdnValueLength,
  [out]     LPWCH  psUnquotedRdnValue
);