HRESULT UiaNavigate(
  [in]  HUIANODE          hnode,
  [in]  NavigateDirection direction,
  [in]  UiaCondition      *pCondition,
  [in]  UiaCacheRequest   *pRequest,
  [out] SAFEARRAY         **ppRequestedData,
  [out] BSTR              *ppTreeStructure
);