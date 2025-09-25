typedef struct {
  ULONG                              Version;
  ISCSI_LOGIN_OPTIONS_INFO_SPECIFIED InformationSpecified;
  ISCSI_LOGIN_FLAGS                  LoginFlags;
  ISCSI_AUTH_TYPES                   AuthType;
  ISCSI_DIGEST_TYPES                 HeaderDigest;
  ISCSI_DIGEST_TYPES                 DataDigest;
  ULONG                              MaximumConnections;
  ULONG                              DefaultTime2Wait;
  ULONG                              DefaultTime2Retain;
  ULONG                              UsernameLength;
  ULONG                              PasswordLength;
  PUCHAR                             Username;
  PUCHAR                             Password;
} ISCSI_LOGIN_OPTIONS, *PISCSI_LOGIN_OPTIONS;