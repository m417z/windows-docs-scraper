typedef enum _D3DKMT_QUERYSTATISTICS_QUEUE_PACKET_TYPE {
  D3DKMT_RenderCommandBuffer,
  D3DKMT_DeferredCommandBuffer,
  D3DKMT_SystemCommandBuffer,
  D3DKMT_MmIoFlipCommandBuffer,
  D3DKMT_WaitCommandBuffer,
  D3DKMT_SignalCommandBuffer,
  D3DKMT_DeviceCommandBuffer,
  D3DKMT_SoftwareCommandBuffer,
  D3DKMT_QueuePacketTypeMax
} D3DKMT_QUERYSTATISTICS_QUEUE_PACKET_TYPE;