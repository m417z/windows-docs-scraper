DWORD EapHostPeerQueryUserBlobFromCredentialInputFields(
  [in]      HANDLE                             hUserImpersonationToken,
  [in]      EAP_METHOD_TYPE                    eapMethodType,
  [in]      DWORD                              dwFlags,
  [in]      DWORD                              dwEapConnDataSize,
  [in]      const BYTE                         *pbEapConnData,
  [in]      const EAP_CONFIG_INPUT_FIELD_ARRAY *pEapConfigInputFieldArray,
  [in, out] DWORD                              *pdwUserBlobSize,
  [in, out] BYTE                               **ppbUserBlob,
  [out]     EAP_ERROR                          **ppEapError
);