typedef struct _WS_SECURITY_ALGORITHM_SUITE {
  WS_SECURITY_ALGORITHM_ID       canonicalizationAlgorithm;
  WS_SECURITY_ALGORITHM_ID       digestAlgorithm;
  WS_SECURITY_ALGORITHM_ID       symmetricSignatureAlgorithm;
  WS_SECURITY_ALGORITHM_ID       asymmetricSignatureAlgorithm;
  WS_SECURITY_ALGORITHM_ID       encryptionAlgorithm;
  WS_SECURITY_ALGORITHM_ID       keyDerivationAlgorithm;
  WS_SECURITY_ALGORITHM_ID       symmetricKeyWrapAlgorithm;
  WS_SECURITY_ALGORITHM_ID       asymmetricKeyWrapAlgorithm;
  ULONG                          minSymmetricKeyLength;
  ULONG                          maxSymmetricKeyLength;
  ULONG                          minAsymmetricKeyLength;
  ULONG                          maxAsymmetricKeyLength;
  WS_SECURITY_ALGORITHM_PROPERTY *properties;
  ULONG                          propertyCount;
} WS_SECURITY_ALGORITHM_SUITE;