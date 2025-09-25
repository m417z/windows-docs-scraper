HRESULT Invoke(
  [in]      PVOID      pvInstance,
  [in]      MEMBERID   memid,
  [in]      WORD       wFlags,
  [in, out] DISPPARAMS *pDispParams,
  [out]     VARIANT    *pVarResult,
  [out]     EXCEPINFO  *pExcepInfo,
  [out]     UINT       *puArgErr
);