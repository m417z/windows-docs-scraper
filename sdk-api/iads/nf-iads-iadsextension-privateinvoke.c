HRESULT PrivateInvoke(
  [in]  DISPID       dispidMember,
  [in]  REFIID       riid,
  [in]  LCID         lcid,
  [in]  WORD         wFlags,
  [in]  DISPPARAMS   *pdispparams,
  [out] VARIANT      *pvarResult,
  [out] EXCEPINFO    *pexcepinfo,
  [out] unsigned int *puArgErr
);