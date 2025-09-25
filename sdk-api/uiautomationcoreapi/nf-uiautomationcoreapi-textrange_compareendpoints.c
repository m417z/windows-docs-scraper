HRESULT TextRange_CompareEndpoints(
  [in]  HUIATEXTRANGE            hobj,
  [in]  TextPatternRangeEndpoint endpoint,
  [in]  HUIATEXTRANGE            targetRange,
  [in]  TextPatternRangeEndpoint targetEndpoint,
  [out] int                      *pRetVal
);