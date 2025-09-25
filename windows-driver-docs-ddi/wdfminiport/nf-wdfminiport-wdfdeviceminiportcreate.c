NTSTATUS WdfDeviceMiniportCreate(
  [in]           WDFDRIVER              Driver,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [in]           PDEVICE_OBJECT         DeviceObject,
  [in, optional] PDEVICE_OBJECT         AttachedDeviceObject,
  [in, optional] PDEVICE_OBJECT         Pdo,
  [out]          WDFDEVICE              *Device
);