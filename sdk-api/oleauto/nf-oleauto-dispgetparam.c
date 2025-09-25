HRESULT DispGetParam(
  [in]            DISPPARAMS *pdispparams,
                  UINT       position,
                  VARTYPE    vtTarg,
  [out]           VARIANT    *pvarResult,
  [out, optional] UINT       *puArgErr
);