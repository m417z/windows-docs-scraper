SECURITY_STATUS TokenBindingGenerateBinding(
  [in]            TOKENBINDING_KEY_PARAMETERS_TYPE keyType,
  [in]            PCWSTR                           targetURL,
  [in]            TOKENBINDING_TYPE                bindingType,
  [in]            const void                       *tlsEKM,
  [in]            DWORD                            tlsEKMSize,
  [in]            TOKENBINDING_EXTENSION_FORMAT    extensionFormat,
  [in]            const void                       *extensionData,
  [out]           void                             **tokenBinding,
  [out]           DWORD                            *tokenBindingSize,
  [out, optional] TOKENBINDING_RESULT_DATA         **resultData
);