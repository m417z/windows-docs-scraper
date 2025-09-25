NTSTATUS UfxDeviceCreate(
                 WDFDEVICE                WdfDevice,
  [in]           PUFX_DEVICE_CALLBACKS    Callbacks,
  [in]           PUFX_DEVICE_CAPABILITIES Capabilities,
  [in, optional] PWDF_OBJECT_ATTRIBUTES   Attributes,
  [out]          UFXDEVICE                *UfxDevice
);