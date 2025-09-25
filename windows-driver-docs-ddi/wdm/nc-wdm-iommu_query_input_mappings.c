IOMMU_QUERY_INPUT_MAPPINGS IommuQueryInputMappings;

NTSTATUS IommuQueryInputMappings(
  [_In_]     PDEVICE_OBJECT PhysicalDeviceObject,
  [_Inout_]  PINPUT_MAPPING_ELEMENT Buffer,
  [_In_]     ULONG BufferLength,
  [_Out_opt] PULONG ReturnLength
)
{...}