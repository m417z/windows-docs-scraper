HRESULT WTSSetRenderHint(
  [in, out] UINT64 *pRenderHintID,
  [in]      HWND   hwndOwner,
  [in]      DWORD  renderHintType,
  [in]      DWORD  cbHintDataLength,
  [in]      BYTE   *pHintData
);