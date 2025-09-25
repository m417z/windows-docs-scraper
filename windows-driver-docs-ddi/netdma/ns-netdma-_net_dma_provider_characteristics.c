typedef struct _NET_DMA_PROVIDER_CHARACTERISTICS {
  UCHAR                             MajorVersion;
  UCHAR                             MinorVersion;
  USHORT                            Size;
  ULONG                             Flags;
  PDEVICE_OBJECT                    PhysicalDeviceObject;
  ULONG                             MaxDmaChannelCount;
  DMA_CHANNELS_CPU_AFFINITY_HANDLER SetDmaChannelCpuAffinity;
  DMA_CHANNEL_ALLOCATE_HANDLER      AllocateDmaChannel;
  DMA_CHANNEL_FREE_HANDLER          FreeDmaChannel;
  DMA_START_HANDLER                 StartDma;
  DMA_SUSPEND_HANDLER               SuspendDma;
  DMA_RESUME_HANDLER                ResumeDma;
  DMA_ABORT_HANDLER                 AbortDma;
  DMA_APPEND_HANDLER                AppendDma;
  DMA_RESET_HANDLER                 ResetChannel;
  UNICODE_STRING                    FriendlyName;
} NET_DMA_PROVIDER_CHARACTERISTICS, *PNET_DMA_PROVIDER_CHARACTERISTICS;