typedef struct _KERB_CERTIFICATE_S4U_LOGON {
  KERB_LOGON_SUBMIT_TYPE MessageType;
  ULONG                  Flags;
  UNICODE_STRING         UserPrincipalName;
  UNICODE_STRING         DomainName;
  ULONG                  CertificateLength;
  PUCHAR                 Certificate;
} KERB_CERTIFICATE_S4U_LOGON, *PKERB_CERTIFICATE_S4U_LOGON;