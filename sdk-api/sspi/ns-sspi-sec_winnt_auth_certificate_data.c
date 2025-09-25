typedef struct _SEC_WINNT_AUTH_CERTIFICATE_DATA {
  unsigned short             cbHeaderLength;
  unsigned short             cbStructureLength;
  SEC_WINNT_AUTH_BYTE_VECTOR Certificate;
} SEC_WINNT_AUTH_CERTIFICATE_DATA, *PSEC_WINNT_AUTH_CERTIFICATE_DATA;