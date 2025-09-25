typedef struct _MSiSCSI_InitiatorLoginStatistics {
  ULONGLONG UniqueAdapterId;
  ULONG     LoginAcceptRsps;
  ULONG     LoginOtherFailRsps;
  ULONG     LoginRedirectRsps;
  ULONG     LoginAuthFailRsps;
  ULONG     LoginAuthenticateFails;
  ULONG     LoginNegotiateFails;
  ULONG     LogoutNormals;
  ULONG     LogoutOtherCodes;
  ULONG     LoginFailures;
} MSiSCSI_InitiatorLoginStatistics, *PMSiSCSI_InitiatorLoginStatistics;