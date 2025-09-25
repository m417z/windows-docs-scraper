typedef struct _MPR_DEVICE_1 {
  WCHAR  szDeviceType[MPR_MaxDeviceType + 1];
  WCHAR  szDeviceName[MPR_MaxDeviceName + 1];
  WCHAR  szLocalPhoneNumber[MPR_MaxPhoneNumber + 1];
  PWCHAR szAlternates;
} MPR_DEVICE_1, *PMPR_DEVICE_1;