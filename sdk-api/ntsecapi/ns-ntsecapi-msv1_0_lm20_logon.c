typedef struct _MSV1_0_LM20_LOGON {
  MSV1_0_LOGON_SUBMIT_TYPE MessageType;
  UNICODE_STRING           LogonDomainName;
  UNICODE_STRING           UserName;
  UNICODE_STRING           Workstation;
  UCHAR                    ChallengeToClient[MSV1_0_CHALLENGE_LENGTH];
  STRING                   CaseSensitiveChallengeResponse;
  STRING                   CaseInsensitiveChallengeResponse;
  ULONG                    ParameterControl;
} MSV1_0_LM20_LOGON, *PMSV1_0_LM20_LOGON;