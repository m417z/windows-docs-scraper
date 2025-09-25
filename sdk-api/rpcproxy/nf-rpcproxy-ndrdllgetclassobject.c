HRESULT NdrDllGetClassObject(
  [in]  REFCLSID            rclsid,
  [in]  REFIID              riid,
  [out] void                **ppv,
  [in]  const ProxyFileInfo **pProxyFileList,
  [in]  const CLSID         *pclsid,
  [in]  CStdPSFactoryBuffer *pPSFactoryBuffer
);