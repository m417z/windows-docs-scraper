typedef struct peer_security_interface_tag {
  DWORD                           dwSize;
  PWSTR                           pwzSspFilename;
  PWSTR                           pwzPackageName;
  ULONG                           cbSecurityInfo;
  PBYTE                           pbSecurityInfo;
  PVOID                           pvContext;
  PFNPEER_VALIDATE_RECORD         pfnValidateRecord;
  PFNPEER_SECURE_RECORD           pfnSecureRecord;
  PFNPEER_FREE_SECURITY_DATA      pfnFreeSecurityData;
  PFNPEER_ON_PASSWORD_AUTH_FAILED pfnAuthFailed;
} PEER_SECURITY_INTERFACE, *PPEER_SECURITY_INTERFACE;