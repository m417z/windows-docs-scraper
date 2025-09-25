NTSTATUS AddStreamResource2(
  [in]  PDEVICE_OBJECT               PhysicalDeviceObject,
  [in]  PVOID                        ResourceSet,
  [in]  PPCSTREAMRESOURCE_DESCRIPTOR ResourceDescriptor,
  [out] PCSTREAMRESOURCE             *ResourceHandle
);