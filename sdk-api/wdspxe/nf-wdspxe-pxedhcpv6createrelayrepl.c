DWORD PXEAPI PxeDhcpv6CreateRelayRepl(
  [in]  PPXE_DHCPV6_NESTED_RELAY_MESSAGE pRelayMessages,
  [in]  ULONG                            nRelayMessages,
  [in]  PBYTE                            pInnerPacket,
  [in]  ULONG                            cbInnerPacket,
  [out] PVOID                            pReplyBuffer,
  [in]  ULONG                            cbReplyBuffer,
  [out] PULONG                           pcbReplyBuffer
);