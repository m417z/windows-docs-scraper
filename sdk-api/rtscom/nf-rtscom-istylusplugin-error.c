HRESULT Error(
  [in]      IRealTimeStylus            *piRtsSrc,
  [in]      IStylusPlugin              *piPlugin,
  [in]      RealTimeStylusDataInterest dataInterest,
  [in]      HRESULT                    hrErrorCode,
  [in, out] LONG_PTR                   *lptrKey
);