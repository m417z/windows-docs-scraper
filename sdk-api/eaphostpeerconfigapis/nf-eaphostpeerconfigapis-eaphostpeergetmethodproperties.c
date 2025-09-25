DWORD EapHostPeerGetMethodProperties(
  [in]  DWORD                     dwVersion,
  [in]  DWORD                     dwFlags,
  [in]  EAP_METHOD_TYPE           eapMethodType,
  [in]  HANDLE                    hUserImpersonationToken,
  [in]  DWORD                     dwEapConnDataSize,
  [in]  const BYTE                *pbEapConnData,
  [in]  DWORD                     dwUserDataSize,
  [in]  const BYTE                *pbUserData,
  [out] EAP_METHOD_PROPERTY_ARRAY *pMethodPropertyArray,
  [out] EAP_ERROR                 **ppEapError
);