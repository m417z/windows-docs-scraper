typedef struct _CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION {
  ULONG ulAuthenticationPackage;
  GUID  clsidCredentialProvider;
  ULONG cbSerialization;
  byte  *rgbSerialization;
} CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION;