typedef struct _STI_DEVICE_INFORMATIONW {
  DWORD           dwSize;
  STI_DEVICE_TYPE DeviceType;
  WCHAR           szDeviceInternalName[STI_MAX_INTERNAL_NAME_LENGTH];
  STI_DEV_CAPS    DeviceCapabilities;
  DWORD           dwHardwareConfiguration;
  LPWSTR          pszVendorDescription;
  LPWSTR          pszDeviceDescription;
  LPWSTR          pszPortName;
  LPWSTR          pszPropProvider;
  LPWSTR          pszLocalName;
} STI_DEVICE_INFORMATIONW, *PSTI_DEVICE_INFORMATIONW;