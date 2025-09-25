typedef struct peer_application_registration_info_tag {
  PEER_APPLICATION application;
  PWSTR            pwzApplicationToLaunch;
  PWSTR            pwzApplicationArguments;
  DWORD            dwPublicationScope;
} PEER_APPLICATION_REGISTRATION_INFO, *PPEER_APPLICATION_REGISTRATION_INFO;