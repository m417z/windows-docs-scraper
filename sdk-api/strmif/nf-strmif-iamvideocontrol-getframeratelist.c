HRESULT GetFrameRateList(
  [in]  IPin     *pPin,
  [in]  long     iIndex,
  [in]  SIZE     Dimensions,
  [out] long     *ListSize,
  [out] LONGLONG **FrameRates
);