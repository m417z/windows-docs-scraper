typedef struct _SEC_WINNT_AUTH_FIDO_DATA {
  unsigned short             cbHeaderLength;
  unsigned short             cbStructureLength;
  SEC_WINNT_AUTH_BYTE_VECTOR Secret;
  SEC_WINNT_AUTH_BYTE_VECTOR NewSecret;
  SEC_WINNT_AUTH_BYTE_VECTOR EncryptedNewSecret;
  SEC_WINNT_AUTH_BYTE_VECTOR NetworkLogonBuffer;
  ULONG64                    ulSignatureCount;
} SEC_WINNT_AUTH_FIDO_DATA, *PSEC_WINNT_AUTH_FIDO_DATA;