typedef struct _SEC_WINNT_AUTH_NGC_DATA {
  LUID                       LogonId;
  unsigned long              Flags;
  SEC_WINNT_AUTH_BYTE_VECTOR CspInfo;
  SEC_WINNT_AUTH_BYTE_VECTOR UserIdKeyAuthTicket;
  SEC_WINNT_AUTH_BYTE_VECTOR DecryptionKeyName;
  SEC_WINNT_AUTH_BYTE_VECTOR DecryptionKeyAuthTicket;
} SEC_WINNT_AUTH_NGC_DATA, *PSEC_WINNT_AUTH_NGC_DATA;