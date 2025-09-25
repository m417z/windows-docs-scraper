WS_DURATION_COMPARISON_CALLBACK WsDurationComparisonCallback;

HRESULT WsDurationComparisonCallback(
  [in]           const WS_DURATION *duration1,
  [in]           const WS_DURATION *duration2,
  [out]          int *result,
  [in, optional] WS_ERROR *error
)
{...}