HRESULT SwDeviceCreate(
  [in]           PCWSTR                      pszEnumeratorName,
  [in]           PCWSTR                      pszParentDeviceInstance,
  [in]           const SW_DEVICE_CREATE_INFO *pCreateInfo,
  [in]           ULONG                       cPropertyCount,
  [in, optional] const DEVPROPERTY           *pProperties,
  [in]           SW_DEVICE_CREATE_CALLBACK   pCallback,
  [in, optional] PVOID                       pContext,
  [out]          PHSWDEVICE                  phSwDevice
);