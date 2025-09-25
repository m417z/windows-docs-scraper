typedef struct _STOR_UNIT_ATTRIBUTES {
  ULONG DeviceAttentionSupported : 1;
  ULONG AsyncNotificationSupported : 1;
  ULONG D3ColdNotSupported : 1;
  ULONG BypassIOSupported : 1;
  ULONG Reserved : 28;
} STOR_UNIT_ATTRIBUTES, *PSTOR_UNIT_ATTRIBUTES;