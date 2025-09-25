typedef struct _NET_DMA_PROVIDER_ATTRIBUTES {
  UCHAR            MajorHwVersion;
  UCHAR            MinorHwVersion;
  USHORT           Size;
  ULONG            Flags;
  ULONG            VendorId;
  ULONG            DmaChannelCount;
  ULONG            MaximumTransferSize;
  PHYSICAL_ADDRESS MaximumAddressSpace;
} NET_DMA_PROVIDER_ATTRIBUTES, *PNET_DMA_PROVIDER_ATTRIBUTES;