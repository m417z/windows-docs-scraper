HRESULT Print(
  [in]      DWORD             grfFlags,
  [in, out] DVTARGETDEVICE    **pptd,
  [in, out] PAGESET           **ppPageSet,
  [in, out] STGMEDIUM         *pstgmOptions,
  [in]      IContinueCallback *pcallback,
  [in]      LONG              nFirstPage,
  [out]     LONG              *pcPagesPrinted,
  [out]     LONG              *pnLastPage
);