VIDEOPORT_DEPRECATED VIDEOPORT_API BOOLEAN VideoPortLockPages(
  [in]      IN PVOID                     HwDeviceExtension,
  [in, out] IN OUT PVIDEO_REQUEST_PACKET pVrp,
  [in]      IN PEVENT                    pUEvent,
  [in]      IN PEVENT                    pDisplayEvent,
  [in]      IN DMA_FLAGS                 DmaFlags
);