typedef struct _DHCP_CALLOUT_TABLE {
  LPDHCP_CONTROL        DhcpControlHook;
  LPDHCP_NEWPKT         DhcpNewPktHook;
  LPDHCP_DROP_SEND      DhcpPktDropHook;
  LPDHCP_DROP_SEND      DhcpPktSendHook;
  LPDHCP_PROB           DhcpAddressDelHook;
  LPDHCP_GIVE_ADDRESS   DhcpAddressOfferHook;
  LPDHCP_HANDLE_OPTIONS DhcpHandleOptionsHook;
  LPDHCP_DELETE_CLIENT  DhcpDeleteClientHook;
  LPVOID                DhcpExtensionHook;
  LPVOID                DhcpReservedHook;
} DHCP_CALLOUT_TABLE, *LPDHCP_CALLOUT_TABLE;