typedef enum _WDF_MEMORY_DESCRIPTOR_TYPE {
  WdfMemoryDescriptorTypeInvalid = 0,
  WdfMemoryDescriptorTypeBuffer,
  WdfMemoryDescriptorTypeMdl,
  WdfMemoryDescriptorTypeHandle
} WDF_MEMORY_DESCRIPTOR_TYPE;