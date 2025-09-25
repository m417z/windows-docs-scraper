typedef struct _WS_DURATION_DESCRIPTION {
  WS_DURATION                     minValue;
  WS_DURATION                     maxValue;
  WS_DURATION_COMPARISON_CALLBACK comparer;
} WS_DURATION_DESCRIPTION;