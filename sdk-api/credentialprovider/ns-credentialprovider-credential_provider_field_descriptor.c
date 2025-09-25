typedef struct _CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR {
  DWORD                          dwFieldID;
  CREDENTIAL_PROVIDER_FIELD_TYPE cpft;
  LPWSTR                         pszLabel;
  GUID                           guidFieldType;
} CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR;