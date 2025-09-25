STORPORT_API STOR_PHYSICAL_ADDRESS StorPortGetPhysicalAddress(
  [in]           PVOID               HwDeviceExtension,
  [in, optional] PSCSI_REQUEST_BLOCK Srb,
  [in]           PVOID               VirtualAddress,
  [out]          ULONG               *Length
);