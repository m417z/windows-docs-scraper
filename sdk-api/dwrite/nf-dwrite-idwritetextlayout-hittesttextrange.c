HRESULT HitTestTextRange(
                  UINT32                  textPosition,
                  UINT32                  textLength,
                  FLOAT                   originX,
                  FLOAT                   originY,
  [out, optional] DWRITE_HIT_TEST_METRICS *hitTestMetrics,
                  UINT32                  maxHitTestMetricsCount,
  [out]           UINT32                  *actualHitTestMetricsCount
);