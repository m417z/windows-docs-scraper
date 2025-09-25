typedef struct WINTRUST_SGNR_INFO_ {
  DWORD            cbStruct;
  LPCWSTR          pcwszDisplayName;
  CMSG_SIGNER_INFO *psSignerInfo;
  DWORD            chStores;
  HCERTSTORE       *pahStores;
} WINTRUST_SGNR_INFO, *PWINTRUST_SGNR_INFO;