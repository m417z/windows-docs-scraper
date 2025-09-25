SECURITY_STATUS TokenBindingGenerateID(
  [in]  TOKENBINDING_KEY_PARAMETERS_TYPE keyType,
  [in]  const void                       *publicKey,
  [in]  DWORD                            publicKeySize,
  [out] TOKENBINDING_RESULT_DATA         **resultData
);