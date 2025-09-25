DSPARSE DWORD DsUnquoteRdnValueA(
  [in]      DWORD cQuotedRdnValueLength,
  [in]      LPCCH psQuotedRdnValue,
  [in, out] DWORD *pcUnquotedRdnValueLength,
  [out]     LPCH  psUnquotedRdnValue
);