typedef struct _NET_DMA_CHANNEL_PARAMETERS {
  USHORT           Revision;
  USHORT           Size;
  ULONG            Flags;
  PVOID            CompletionVirtualAddress;
  PHYSICAL_ADDRESS CompletionPhysicalAddress;
  ULONG            ProcessorAffinityMask;
  ULONG            ChannelPriority;
  ULONG            CpuNumber;
  GROUP_AFFINITY   ProcessorAffinityMaskEx;
} NET_DMA_CHANNEL_PARAMETERS, *PNET_DMA_CHANNEL_PARAMETERS;