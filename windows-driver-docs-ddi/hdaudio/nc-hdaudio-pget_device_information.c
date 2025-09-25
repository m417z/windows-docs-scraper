PGET_DEVICE_INFORMATION PgetDeviceInformation;

NTSTATUS PgetDeviceInformation(
  [in]      PVOID _context,
  [in, out] PHDAUDIO_DEVICE_INFORMATION DeviceInformation
)
{...}