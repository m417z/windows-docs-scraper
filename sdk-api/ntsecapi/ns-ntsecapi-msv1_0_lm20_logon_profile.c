typedef struct _MSV1_0_LM20_LOGON_PROFILE {
  MSV1_0_PROFILE_BUFFER_TYPE MessageType;
  LARGE_INTEGER              KickOffTime;
  LARGE_INTEGER              LogoffTime;
  ULONG                      UserFlags;
  UCHAR                      UserSessionKey[MSV1_0_USER_SESSION_KEY_LENGTH];
  UNICODE_STRING             LogonDomainName;
  UCHAR                      LanmanSessionKey[MSV1_0_LANMAN_SESSION_KEY_LENGTH];
  UNICODE_STRING             LogonServer;
  UNICODE_STRING             UserParameters;
} MSV1_0_LM20_LOGON_PROFILE, *PMSV1_0_LM20_LOGON_PROFILE;