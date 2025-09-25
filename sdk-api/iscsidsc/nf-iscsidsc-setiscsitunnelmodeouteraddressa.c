ISDSC_STATUS ISDSC_API SetIScsiTunnelModeOuterAddressA(
  [in, optional] PSTR    InitiatorName,
  [in]           ULONG   InitiatorPortNumber,
  [in]           PSTR    DestinationAddress,
  [in]           PSTR    OuterModeAddress,
  [in]           BOOLEAN Persist
);