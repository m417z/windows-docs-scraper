HRESULT TxDraw(
  [in] DWORD           dwDrawAspect,
       LONG            lindex,
  [in] void            *pvAspect,
  [in] DVTARGETDEVICE  *ptd,
  [in] HDC             hdcDraw,
  [in] HDC             hicTargetDev,
  [in] LPCRECTL        lprcBounds,
  [in] LPCRECTL        lprcWBounds,
  [in] LPRECT          lprcUpdate,
       BOOL(* )(DWORD) pfnContinue,
       DWORD           dwContinue,
       LONG            lViewId
);