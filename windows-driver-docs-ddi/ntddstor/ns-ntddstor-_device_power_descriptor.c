typedef struct _DEVICE_POWER_DESCRIPTOR {
  ULONG   Version;
  ULONG   Size;
  BOOLEAN DeviceAttentionSupported;
  BOOLEAN AsynchronousNotificationSupported;
  BOOLEAN IdlePowerManagementEnabled;
  BOOLEAN D3ColdEnabled;
  BOOLEAN D3ColdSupported;
  BOOLEAN NoVerifyDuringIdlePower;
  UCHAR   Reserved[2];
  ULONG   IdleTimeoutInMS;
} DEVICE_POWER_DESCRIPTOR, *PDEVICE_POWER_DESCRIPTOR;