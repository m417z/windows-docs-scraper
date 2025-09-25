HRESULT Draw(
  [in] DWORD                          dwDrawAspect,
  [in] LONG                           lindex,
  [in] void                           *pvAspect,
  [in] DVTARGETDEVICE                 *ptd,
  [in] HDC                            hdcTargetDev,
  [in] HDC                            hdcDraw,
  [in] LPCRECTL                       lprcBounds,
  [in] LPCRECTL                       lprcWBounds,
  [in] BOOL(* )(ULONG_PTR dwContinue) pfnContinue,
  [in] ULONG_PTR                      dwContinue
);