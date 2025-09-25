typedef struct _WKSTA_USER_INFO_1 {
  LMSTR wkui1_username;
  LMSTR wkui1_logon_domain;
  LMSTR wkui1_oth_domains;
  LMSTR wkui1_logon_server;
} WKSTA_USER_INFO_1, *PWKSTA_USER_INFO_1, *LPWKSTA_USER_INFO_1;