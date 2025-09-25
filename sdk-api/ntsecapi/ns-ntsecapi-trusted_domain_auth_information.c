typedef struct _TRUSTED_DOMAIN_AUTH_INFORMATION {
  ULONG                 IncomingAuthInfos;
  PLSA_AUTH_INFORMATION IncomingAuthenticationInformation;
  PLSA_AUTH_INFORMATION IncomingPreviousAuthenticationInformation;
  ULONG                 OutgoingAuthInfos;
  PLSA_AUTH_INFORMATION OutgoingAuthenticationInformation;
  PLSA_AUTH_INFORMATION OutgoingPreviousAuthenticationInformation;
} TRUSTED_DOMAIN_AUTH_INFORMATION, *PTRUSTED_DOMAIN_AUTH_INFORMATION;