NTSTATUS WdfIoTargetQueryTargetProperty(
  [in]            WDFIOTARGET              IoTarget,
  [in]            DEVICE_REGISTRY_PROPERTY DeviceProperty,
  [in]            ULONG                    BufferLength,
  [out, optional] PVOID                    PropertyBuffer,
  [out]           PULONG                   ResultLength
);