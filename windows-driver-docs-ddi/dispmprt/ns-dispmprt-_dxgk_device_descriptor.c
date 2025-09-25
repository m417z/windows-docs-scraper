typedef struct _DXGK_DEVICE_DESCRIPTOR {
  ULONG                                          DescriptorOffset;
  ULONG                                          DescriptorLength;
  _Field_size_bytes_DXGK_(DescriptorLength)PVOID DescriptorBuffer;
} DXGK_DEVICE_DESCRIPTOR, *PDXGK_DEVICE_DESCRIPTOR;