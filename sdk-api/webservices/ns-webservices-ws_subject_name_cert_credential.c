typedef struct _WS_SUBJECT_NAME_CERT_CREDENTIAL {
  WS_CERT_CREDENTIAL credential;
  ULONG              storeLocation;
  WS_STRING          storeName;
  WS_STRING          subjectName;
} WS_SUBJECT_NAME_CERT_CREDENTIAL;