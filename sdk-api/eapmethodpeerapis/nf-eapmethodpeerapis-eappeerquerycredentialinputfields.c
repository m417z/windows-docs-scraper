DWORD EapPeerQueryCredentialInputFields(
  [in]  HANDLE                       hUserImpersonationToken,
  [in]  EAP_METHOD_TYPE              eapMethodType,
  [in]  DWORD                        dwFlags,
  [in]  DWORD                        dwEapConnDataSize,
  [in]  BYTE                         *pbEapConnData,
  [out] EAP_CONFIG_INPUT_FIELD_ARRAY *pEapConfigFieldsArray,
  [out] EAP_ERROR                    **ppEapError
);