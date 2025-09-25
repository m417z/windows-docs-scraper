HRESULT FindWindowSW(
  [in]          VARIANT   *pvarLoc,
  [in]          VARIANT   *pvarLocRoot,
  [in]          int       swClass,
  [out]         long      *phwnd,
                int       swfwOptions,
  [out, retval] IDispatch **ppdispOut
);