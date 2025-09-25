SECURITY_STATUS TokenBindingVerifyMessage(
  [in]  const void                       *tokenBindingMessage,
  [in]  DWORD                            tokenBindingMessageSize,
  [in]  TOKENBINDING_KEY_PARAMETERS_TYPE keyType,
  [in]  const void                       *tlsEKM,
  [in]  DWORD                            tlsEKMSize,
  [out] TOKENBINDING_RESULT_LIST         **resultList
);