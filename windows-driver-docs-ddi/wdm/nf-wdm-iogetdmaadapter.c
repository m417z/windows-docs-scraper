_DMA_ADAPTER * IoGetDmaAdapter(
  [in, optional] PDEVICE_OBJECT      PhysicalDeviceObject,
  [in]           _DEVICE_DESCRIPTION *DeviceDescription,
  [out]          PULONG              NumberOfMapRegisters
);