typedef struct _CRYPTUI_WIZ_DIGITAL_SIGN_INFO {
  DWORD                                    dwSize;
  DWORD                                    dwSubjectChoice;
  union {
    LPCWSTR                              pwszFileName;
    PCCRYPTUI_WIZ_DIGITAL_SIGN_BLOB_INFO pSignBlobInfo;
  };
  DWORD                                    dwSigningCertChoice;
  union {
    PCCERT_CONTEXT                           pSigningCertContext;
    PCCRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO    pSigningCertStore;
    PCCRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO pSigningCertPvkInfo;
  };
  LPCWSTR                                  pwszTimestampURL;
  DWORD                                    dwAdditionalCertChoice;
  PCCRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO pSignExtInfo;
} CRYPTUI_WIZ_DIGITAL_SIGN_INFO, *PCRYPTUI_WIZ_DIGITAL_SIGN_INFO;