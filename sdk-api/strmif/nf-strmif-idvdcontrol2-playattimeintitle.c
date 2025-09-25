HRESULT PlayAtTimeInTitle(
  [in]  ULONG             ulTitle,
  [in]  DVD_HMSF_TIMECODE *pStartTime,
  [in]  DWORD             dwFlags,
  [out] IDvdCmd           **ppCmd
);