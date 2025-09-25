DWORD EapPeerGetMethodProperties(
  [in]  DWORD                     dwVersion,
  [in]  DWORD                     dwFlags,
  [in]  EAP_METHOD_TYPE           eapMethodType,
  [in]  HANDLE                    hUserImpersonationToken,
  [in]  DWORD                     dwSizeOfConnectionDataIn,
  [in]  const BYTE                *pConnectionDataIn,
  [in]  DWORD                     dwSizeOfUserDataIn,
  [in]  const BYTE                *pUserDataIn,
  [out] EAP_METHOD_PROPERTY_ARRAY *pMethodPropertyArray,
  [out] EAP_ERROR                 **ppEapError
);