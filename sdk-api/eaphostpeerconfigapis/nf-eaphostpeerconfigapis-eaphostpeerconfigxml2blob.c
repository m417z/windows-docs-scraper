DWORD EapHostPeerConfigXml2Blob(
  [in]  DWORD           dwFlags,
  [in]  IXMLDOMNode     *pConfigDoc,
  [out] DWORD           *pdwSizeOfConfigOut,
  [out] BYTE            **ppConfigOut,
  [out] EAP_METHOD_TYPE *pEapMethodType,
  [out] EAP_ERROR       **ppEapError
);