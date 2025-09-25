typedef struct _DMA_ADAPTER_INFO_CRASHDUMP {
  DEVICE_DESCRIPTION DeviceDescription;
  SIZE_T             DeviceIdSize;
  PVOID              DeviceId;
} DMA_ADAPTER_INFO_CRASHDUMP, *PDMA_ADAPTER_INFO_CRASHDUMP;