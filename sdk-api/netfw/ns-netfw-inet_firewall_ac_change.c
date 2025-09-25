typedef struct _INET_FIREWALL_AC_CHANGE {
  INET_FIREWALL_AC_CHANGE_TYPE   changeType;
  INET_FIREWALL_AC_CREATION_TYPE createType;
  SID                            *appContainerSid;
  SID                            *userSid;
  LPWSTR                         displayName;
  union {
    INET_FIREWALL_AC_CAPABILITIES capabilities;
    INET_FIREWALL_AC_BINARIES     binaries;
  };
} INET_FIREWALL_AC_CHANGE, *PINET_FIREWALL_AC_CHANGE;