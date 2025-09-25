DWORD EapPeerConfigBlob2Xml(
  [in]  DWORD            dwFlags,
  [in]  EAP_METHOD_TYPE  eapMethodType,
  [in]  const BYTE       *pConfigIn,
  [in]  DWORD            dwSizeOfConfigIn,
  [out] IXMLDOMDocument2 **ppConfigDoc,
  [out] EAP_ERROR        **ppEapError
);