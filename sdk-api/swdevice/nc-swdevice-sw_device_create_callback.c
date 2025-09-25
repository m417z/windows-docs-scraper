SW_DEVICE_CREATE_CALLBACK SwDeviceCreateCallback;

VOID SwDeviceCreateCallback(
  [in]           HSWDEVICE hSwDevice,
  [in]           HRESULT CreateResult,
  [in, optional] PVOID pContext,
  [in, optional] PCWSTR pszDeviceInstanceId
)
{...}