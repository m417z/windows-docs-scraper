DWORD PXEAPI PxeDhcpv6ParseRelayForw(
  [in]  PVOID                            pRelayForwPacket,
  [in]  ULONG                            uRelayForwPacketLen,
  [out] PPXE_DHCPV6_NESTED_RELAY_MESSAGE pRelayMessages,
  [in]  ULONG                            nRelayMessages,
  [out] PULONG                           pnRelayMessages,
  [out] PBYTE                            *ppInnerPacket,
  [out] PULONG                           pcbInnerPacket
);