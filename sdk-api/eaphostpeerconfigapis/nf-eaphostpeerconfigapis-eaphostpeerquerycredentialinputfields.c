DWORD EapHostPeerQueryCredentialInputFields(
  [in]  HANDLE                       hUserImpersonationToken,
  [in]  EAP_METHOD_TYPE              eapMethodType,
  [in]  DWORD                        dwFlags,
  [in]  DWORD                        dwEapConnDataSize,
  [in]  const BYTE                   *pbEapConnData,
  [out] EAP_CONFIG_INPUT_FIELD_ARRAY *pEapConfigInputFieldArray,
  [out] EAP_ERROR                    **ppEapError
);