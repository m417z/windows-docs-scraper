typedef struct _SEC_WINNT_AUTH_PACKED_CREDENTIALS_EX {
  unsigned short              cbHeaderLength;
  unsigned long               Flags;
  SEC_WINNT_AUTH_BYTE_VECTOR  PackedCredentials;
  SEC_WINNT_AUTH_SHORT_VECTOR PackageList;
} SEC_WINNT_AUTH_PACKED_CREDENTIALS_EX, *PSEC_WINNT_AUTH_PACKED_CREDENTIALS_EX;