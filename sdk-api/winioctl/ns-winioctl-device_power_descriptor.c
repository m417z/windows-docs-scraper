typedef struct _DEVICE_POWER_DESCRIPTOR {
  DWORD   Version;
  DWORD   Size;
  BOOLEAN DeviceAttentionSupported;
  BOOLEAN AsynchronousNotificationSupported;
  BOOLEAN IdlePowerManagementEnabled;
  BOOLEAN D3ColdEnabled;
  BOOLEAN D3ColdSupported;
  BOOLEAN NoVerifyDuringIdlePower;
  BYTE    Reserved[2];
  DWORD   IdleTimeoutInMS;
} DEVICE_POWER_DESCRIPTOR, *PDEVICE_POWER_DESCRIPTOR;