typedef struct _KERB_CERTIFICATE_LOGON {
  KERB_LOGON_SUBMIT_TYPE MessageType;
  UNICODE_STRING         DomainName;
  UNICODE_STRING         UserName;
  UNICODE_STRING         Pin;
  ULONG                  Flags;
  ULONG                  CspDataLength;
  PUCHAR                 CspData;
} KERB_CERTIFICATE_LOGON, *PKERB_CERTIFICATE_LOGON;