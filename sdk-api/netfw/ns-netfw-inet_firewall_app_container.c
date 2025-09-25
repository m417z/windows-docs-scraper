typedef struct _INET_FIREWALL_APP_CONTAINER {
  SID                           *appContainerSid;
  SID                           *userSid;
  LPWSTR                        appContainerName;
  LPWSTR                        displayName;
  LPWSTR                        description;
  INET_FIREWALL_AC_CAPABILITIES capabilities;
  INET_FIREWALL_AC_BINARIES     binaries;
  LPWSTR                        workingDirectory;
  LPWSTR                        packageFullName;
} INET_FIREWALL_APP_CONTAINER, *PINET_FIREWALL_APP_CONTAINER;