ISDSC_STATUS ISDSC_API SetIScsiTunnelModeOuterAddressW(
  [in, optional] PWSTR   InitiatorName,
  [in]           ULONG   InitiatorPortNumber,
  [in]           PWSTR   DestinationAddress,
  [in]           PWSTR   OuterModeAddress,
  [in]           BOOLEAN Persist
);