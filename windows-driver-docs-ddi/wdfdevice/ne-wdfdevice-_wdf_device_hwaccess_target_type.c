typedef enum _WDF_DEVICE_HWACCESS_TARGET_TYPE {
  WdfDeviceHwAccessTargetTypeInvalid = 0,
  WdfDeviceHwAccessTargetTypeRegister,
  WdfDeviceHwAccessTargetTypeRegisterBuffer,
  WdfDeviceHwAccessTargetTypePort,
  WdfDeviceHwAccessTargetTypePortBuffer,
  WdfDeviceHwAccessTargetTypeMaximum
} WDF_DEVICE_HWACCESS_TARGET_TYPE, *PWDF_DEVICE_HWACCESS_TARGET_TYPE;