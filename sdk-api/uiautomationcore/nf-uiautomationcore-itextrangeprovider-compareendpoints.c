HRESULT CompareEndpoints(
  [in]          TextPatternRangeEndpoint endpoint,
  [in]          ITextRangeProvider       *targetRange,
  [in]          TextPatternRangeEndpoint targetEndpoint,
  [out, retval] int                      *pRetVal
);