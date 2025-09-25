NTSTATUS WdfUsbTargetDeviceQueryUsbCapability(
  [in]            WDFUSBDEVICE UsbDevice,
  [in]            const GUID   *CapabilityType,
  [in]            ULONG        CapabilityBufferLength,
  [out, optional] PVOID        CapabilityBuffer,
  [out, optional] PULONG       ResultLength
);