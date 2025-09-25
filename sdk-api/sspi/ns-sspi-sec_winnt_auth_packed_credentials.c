typedef struct _SEC_WINNT_AUTH_PACKED_CREDENTIALS {
  unsigned short      cbHeaderLength;
  unsigned short      cbStructureLength;
  SEC_WINNT_AUTH_DATA AuthData;
} SEC_WINNT_AUTH_PACKED_CREDENTIALS, *PSEC_WINNT_AUTH_PACKED_CREDENTIALS;