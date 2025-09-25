typedef struct _TRUSTED_DOMAIN_INFORMATION_EX {
  LSA_UNICODE_STRING Name;
  LSA_UNICODE_STRING FlatName;
  PSID               Sid;
  ULONG              TrustDirection;
  ULONG              TrustType;
  ULONG              TrustAttributes;
} TRUSTED_DOMAIN_INFORMATION_EX, *PTRUSTED_DOMAIN_INFORMATION_EX;