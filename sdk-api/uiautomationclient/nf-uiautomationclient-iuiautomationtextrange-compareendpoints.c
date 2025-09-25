HRESULT CompareEndpoints(
  [in]          TextPatternRangeEndpoint srcEndPoint,
  [in]          IUIAutomationTextRange   *range,
  [in]          TextPatternRangeEndpoint targetEndPoint,
  [out, retval] int                      *compValue
);