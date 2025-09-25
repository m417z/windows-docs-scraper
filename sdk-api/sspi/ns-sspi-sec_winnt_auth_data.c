typedef struct _SEC_WINNT_AUTH_DATA {
  GUID                       CredType;
  SEC_WINNT_AUTH_BYTE_VECTOR CredData;
} SEC_WINNT_AUTH_DATA, *PSEC_WINNT_AUTH_DATA;