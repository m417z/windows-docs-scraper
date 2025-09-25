typedef struct _PKU2U_CERTIFICATE_S4U_LOGON {
  PKU2U_LOGON_SUBMIT_TYPE MessageType;
  ULONG                   Flags;
  UNICODE_STRING          UserPrincipalName;
  UNICODE_STRING          DomainName;
  ULONG                   CertificateLength;
  PUCHAR                  Certificate;
} PKU2U_CERTIFICATE_S4U_LOGON, *PPKU2U_CERTIFICATE_S4U_LOGON;