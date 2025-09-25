VIDEOPORT_DEPRECATED VIDEOPORT_API PDMA VideoPortAssociateEventsWithDmaHandle(
  [in]      IN PVOID                     HwDeviceExtension,
  [in, out] IN OUT PVIDEO_REQUEST_PACKET pVrp,
  [in]      IN PVOID                     MappedUserEvent,
  [in]      IN PVOID                     DisplayDriverEvent
);