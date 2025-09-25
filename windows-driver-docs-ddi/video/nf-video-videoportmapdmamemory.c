VIDEOPORT_DEPRECATED VIDEOPORT_API PDMA VideoPortMapDmaMemory(
  [in]      IN PVOID                 HwDeviceExtension,
  [in]      IN PVIDEO_REQUEST_PACKET pVrp,
  [in]      IN PHYSICAL_ADDRESS      BoardAddress,
  [in]      IN PULONG                Length,
  [in]      IN PULONG                InIoSpace,
  [in]      IN PVOID                 MappedUserEvent,
  [in]      IN PVOID                 DisplayDriverEvent,
  [in, out] IN OUT PVOID             *VirtualAddress
);