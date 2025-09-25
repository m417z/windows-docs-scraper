HRESULT CreateAsyncBindCtx(
  [in]  DWORD               reserved,
  [in]  IBindStatusCallback *pBSCb,
  [in]  IEnumFORMATETC      *pEFetc,
  [out] IBindCtx            **ppBC
);