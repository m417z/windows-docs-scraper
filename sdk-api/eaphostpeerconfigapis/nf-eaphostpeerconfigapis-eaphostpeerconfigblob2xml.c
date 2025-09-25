DWORD EapHostPeerConfigBlob2Xml(
  [in]  DWORD            dwFlags,
  [in]  EAP_METHOD_TYPE  eapMethodType,
  [in]  DWORD            dwSizeOfConfigIn,
  [in]  BYTE             *pConfigIn,
  [out] IXMLDOMDocument2 **ppConfigDoc,
  [out] EAP_ERROR        **ppEapError
);