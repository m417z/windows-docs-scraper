PORTCLASSAPI NTSTATUS PcGetPhysicalDeviceObject(
  [in]  IN PDEVICE_OBJECT  pDeviceObject,
  [out] OUT PDEVICE_OBJECT *ppPhysicalObject
);