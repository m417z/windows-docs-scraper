DWORD EapPeerConfigXml2Blob(
  [in]  DWORD            dwFlags,
  [in]  EAP_METHOD_TYPE  eapMethodType,
  [in]  IXMLDOMDocument2 *pConfigDoc,
  [out] BYTE             **ppConfigOut,
  [out] DWORD            *pdwSizeOfConfigOut,
  [out] EAP_ERROR        **ppEapError
);