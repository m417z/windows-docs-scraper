DWORD EapPeerCredentialsXml2Blob(
  [in]  DWORD            dwFlags,
  [in]  EAP_METHOD_TYPE  eapMethodType,
  [in]  IXMLDOMDocument2 *pCredentialsDoc,
  [in]  const BYTE       *pConfigIn,
  [in]  DWORD            dwSizeOfConfigIn,
  [out] BYTE             **ppCredentialsOut,
  [out] DWORD            *pdwSizeOfCredentialsOut,
  [out] EAP_ERROR        **ppEapError
);