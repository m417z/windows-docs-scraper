VOID NdisMGetDeviceProperty(
  [in]            NDIS_HANDLE       MiniportAdapterHandle,
  [out, optional] PDEVICE_OBJECT    *PhysicalDeviceObject,
  [out, optional] PDEVICE_OBJECT    *FunctionalDeviceObject,
  [out, optional] PDEVICE_OBJECT    *NextDeviceObject,
  [out, optional] PCM_RESOURCE_LIST *AllocatedResources,
  [out, optional] PCM_RESOURCE_LIST *AllocatedResourcesTranslated
);