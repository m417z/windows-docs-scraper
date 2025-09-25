NTSTATUS TrSecureDeviceHandoffServiceDeviceControl(
  PWDFDEVICE_INIT              DeviceInit,
  LPGUID                       ServiceGuid,
  PTR_SECURE_SERVICE_CALLBACKS Callbacks,
  WDFDEVICE                    *ServiceDevice
);