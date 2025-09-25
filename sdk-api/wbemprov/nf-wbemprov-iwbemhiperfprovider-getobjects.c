HRESULT GetObjects(
  [in]      IWbemServices     *pNamespace,
  [in]      long              lNumObjects,
  [in, out] IWbemObjectAccess **apObj,
            long              lFlags,
            IWbemContext      *pContext
);