DWORD EapHostPeerCredentialsXml2Blob(
  [in]  DWORD           dwFlags,
  [in]  IXMLDOMNode     *pCredentialsDoc,
  [in]  DWORD           dwSizeOfConfigIn,
  [in]  BYTE            *pConfigIn,
  [out] DWORD           *pdwSizeOfCredentialsOut,
  [out] BYTE            **ppCredentialsOut,
  [out] EAP_METHOD_TYPE *pEapMethodType,
  [out] EAP_ERROR       **ppEapError
);