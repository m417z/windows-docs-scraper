typedef enum _WDF_DEVICE_HWACCESS_TARGET_SIZE {
  WdfDeviceHwAccessTargetSizeInvalid = 0,
  WdfDeviceHwAccessTargetSizeUchar,
  WdfDeviceHwAccessTargetSizeUshort,
  WdfDeviceHwAccessTargetSizeUlong,
  WdfDeviceHwAccessTargetSizeUlong64,
  WdfDeviceHwAccessTargetSizeMaximum
} WDF_DEVICE_HWACCESS_TARGET_SIZE, *PWDF_DEVICE_HWACCESS_TARGET_SIZE;