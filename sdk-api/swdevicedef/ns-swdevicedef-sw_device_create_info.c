typedef struct _SW_DEVICE_CREATE_INFO {
  ULONG                     cbSize;
  PCWSTR                    pszInstanceId;
  PCZZWSTR                  pszzHardwareIds;
  PCZZWSTR                  pszzCompatibleIds;
  const GUID                *pContainerId;
  ULONG                     CapabilityFlags;
  PCWSTR                    pszDeviceDescription;
  PCWSTR                    pszDeviceLocation;
  const SECURITY_DESCRIPTOR *pSecurityDescriptor;
} SW_DEVICE_CREATE_INFO, *PSW_DEVICE_CREATE_INFO;