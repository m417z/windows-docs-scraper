typedef struct _MSV1_0_SUBAUTH_LOGON {
  MSV1_0_LOGON_SUBMIT_TYPE MessageType;
  UNICODE_STRING           LogonDomainName;
  UNICODE_STRING           UserName;
  UNICODE_STRING           Workstation;
  UCHAR                    ChallengeToClient[MSV1_0_CHALLENGE_LENGTH];
  STRING                   AuthenticationInfo1;
  STRING                   AuthenticationInfo2;
  ULONG                    ParameterControl;
  ULONG                    SubAuthPackageId;
} MSV1_0_SUBAUTH_LOGON, *PMSV1_0_SUBAUTH_LOGON;