HRESULT GetPacketDescriptionPropertyMetrics(
  [in]  BSTR                     PropertyName,
  [out] long                     *Minimum,
  [out] long                     *Maximum,
  [out] TabletPropertyMetricUnit *Units,
  [out] float                    *Resolution
);