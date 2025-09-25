typedef struct _DHCP_FAILOVER_RELATIONSHIP {
  DHCP_IP_ADDRESS      PrimaryServer;
  DHCP_IP_ADDRESS      SecondaryServer;
  DHCP_FAILOVER_MODE   Mode;
  DHCP_FAILOVER_SERVER ServerType;
  FSM_STATE            State;
  FSM_STATE            PrevState;
  DWORD                Mclt;
  DWORD                SafePeriod;
  LPWSTR               RelationshipName;
  LPWSTR               PrimaryServerName;
  LPWSTR               SecondaryServerName;
  LPDHCP_IP_ARRAY      pScopes;
  BYTE                 Percentage;
  LPWSTR               SharedSecret;
} DHCP_FAILOVER_RELATIONSHIP, *LPDHCP_FAILOVER_RELATIONSHIP;