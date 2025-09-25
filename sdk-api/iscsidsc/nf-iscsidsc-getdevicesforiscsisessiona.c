ISDSC_STATUS ISDSC_API GetDevicesForIScsiSessionA(
  [in]      PISCSI_UNIQUE_SESSION_ID  UniqueSessionId,
  [in, out] ULONG                     *DeviceCount,
  [out]     PISCSI_DEVICE_ON_SESSIONA Devices
);