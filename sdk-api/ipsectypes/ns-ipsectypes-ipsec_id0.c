typedef struct IPSEC_ID0_ {
  wchar_t      *mmTargetName;
  wchar_t      *emTargetName;
  UINT32       numTokens;
  IPSEC_TOKEN0 *tokens;
  UINT64       explicitCredentials;
  UINT64       logonId;
} IPSEC_ID0;