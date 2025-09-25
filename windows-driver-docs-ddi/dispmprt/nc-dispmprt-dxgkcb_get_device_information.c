DXGKCB_GET_DEVICE_INFORMATION DxgkcbGetDeviceInformation;

NTSTATUS DxgkcbGetDeviceInformation(
  [in]  HANDLE DeviceHandle,
  [out] PDXGK_DEVICE_INFO DeviceInfo
)
{...}