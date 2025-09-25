typedef struct tagPXE_DHCPV6_NESTED_RELAY_MESSAGE {
  PPXE_DHCPV6_RELAY_MESSAGE pRelayMessage;
  ULONG                     cbRelayMessage;
  PVOID                     pInterfaceIdOption;
  WORD                      cbInterfaceIdOption;
} PXE_DHCPV6_NESTED_RELAY_MESSAGE, *PPXE_DHCPV6_NESTED_RELAY_MESSAGE;