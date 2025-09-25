HRESULT GetPropertyMetrics(
  [in]  BSTR                     propertyName,
  [out] long                     *Minimum,
  [out] long                     *Maximum,
  [out] TabletPropertyMetricUnit *Units,
  [out] float                    *Resolution
);