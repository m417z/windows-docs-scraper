typedef struct _TOKEN_ACCESS_INFORMATION {
  PSID_AND_ATTRIBUTES_HASH     SidHash;
  PSID_AND_ATTRIBUTES_HASH     RestrictedSidHash;
  PTOKEN_PRIVILEGES            Privileges;
  LUID                         AuthenticationId;
  TOKEN_TYPE                   TokenType;
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
  TOKEN_MANDATORY_POLICY       MandatoryPolicy;
  DWORD                        Flags;
  DWORD                        AppContainerNumber;
  PSID                         PackageSid;
  PSID_AND_ATTRIBUTES_HASH     CapabilitiesHash;
  PSID                         TrustLevelSid;
  PSECURITY_ATTRIBUTES_OPAQUE  SecurityAttributes;
} TOKEN_ACCESS_INFORMATION, *PTOKEN_ACCESS_INFORMATION;