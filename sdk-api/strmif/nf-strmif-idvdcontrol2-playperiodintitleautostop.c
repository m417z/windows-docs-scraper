HRESULT PlayPeriodInTitleAutoStop(
  [in]  ULONG             ulTitle,
  [in]  DVD_HMSF_TIMECODE *pStartTime,
  [in]  DVD_HMSF_TIMECODE *pEndTime,
  [in]  DWORD             dwFlags,
  [out] IDvdCmd           **ppCmd
);