DWORD EapPeerQueryUserBlobFromCredentialInputFields(
  [in]      HANDLE                             hUserImpersonationToken,
  [in]      EAP_METHOD_TYPE                    eapMethodType,
  [in]      DWORD                              dwFlags,
  [in]      DWORD                              dwEapConnDataSize,
  [in]      BYTE                               *pbEapConnData,
  [in]      const EAP_CONFIG_INPUT_FIELD_ARRAY *pEapConfigInputFieldArray,
  [in, out] DWORD                              *pdwUserBlobSize,
            BYTE                               **ppUserBlob,
  [out]     EAP_ERROR                          **ppEapError
);