typedef struct _DXGK_DEVICE_INFO {
  PVOID             MiniportDeviceContext;
  PDEVICE_OBJECT    PhysicalDeviceObject;
  UNICODE_STRING    DeviceRegistryPath;
  PCM_RESOURCE_LIST TranslatedResourceList;
  LARGE_INTEGER     SystemMemorySize;
  PHYSICAL_ADDRESS  HighestPhysicalAddress;
  PHYSICAL_ADDRESS  AgpApertureBase;
  SIZE_T            AgpApertureSize;
  DOCKING_STATE     DockingState;
} DXGK_DEVICE_INFO, *PDXGK_DEVICE_INFO;