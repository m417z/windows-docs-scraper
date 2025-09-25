HRESULT GetColorSet(
  [in]  DWORD          dwDrawAspect,
  [in]  LONG           lindex,
  [in]  void           *pvAspect,
  [in]  DVTARGETDEVICE *ptd,
  [in]  HDC            hicTargetDev,
  [out] LOGPALETTE     **ppColorSet
);