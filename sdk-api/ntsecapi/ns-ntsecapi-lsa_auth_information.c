typedef struct _LSA_AUTH_INFORMATION {
  LARGE_INTEGER LastUpdateTime;
  ULONG         AuthType;
  ULONG         AuthInfoLength;
  PUCHAR        AuthInfo;
} LSA_AUTH_INFORMATION, *PLSA_AUTH_INFORMATION;