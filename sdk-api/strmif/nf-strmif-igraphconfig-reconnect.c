HRESULT Reconnect(
  [in] IPin                *pOutputPin,
  [in] IPin                *pInputPin,
  [in] const AM_MEDIA_TYPE *pmtFirstConnection,
  [in] IBaseFilter         *pUsingFilter,
  [in] HANDLE              hAbortEvent,
  [in] DWORD               dwFlags
);