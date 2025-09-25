HRESULT ResolveTypeRef(
  [in]          mdTypeRef tkTypeRef,
  [in]          REFIID    riid,
  [out]         IUnknown  **ppIScope,
  [out, retval] mdTypeDef *ptkTypeDef
);