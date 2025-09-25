HRESULT SeekInUnits(
  [in]            LARGE_INTEGER    dlibMove,
  [in]            WPD_STREAM_UNITS units,
  [in]            DWORD            dwOrigin,
  [out, optional] ULARGE_INTEGER   *plibNewPosition
);