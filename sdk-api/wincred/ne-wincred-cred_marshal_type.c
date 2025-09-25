typedef enum _CRED_MARSHAL_TYPE {
  CertCredential = 1,
  UsernameTargetCredential,
  BinaryBlobCredential,
  UsernameForPackedCredentials,
  BinaryBlobForSystem
} CRED_MARSHAL_TYPE, *PCRED_MARSHAL_TYPE;