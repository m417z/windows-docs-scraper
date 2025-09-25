typedef struct peer_record_tag {
  DWORD     dwSize;
  GUID      type;
  GUID      id;
  DWORD     dwVersion;
  DWORD     dwFlags;
  PWSTR     pwzCreatorId;
  PWSTR     pwzModifiedById;
  PWSTR     pwzAttributes;
  FILETIME  ftCreation;
  FILETIME  ftExpiration;
  FILETIME  ftLastModified;
  PEER_DATA securityData;
  PEER_DATA data;
} PEER_RECORD, *PPEER_RECORD;