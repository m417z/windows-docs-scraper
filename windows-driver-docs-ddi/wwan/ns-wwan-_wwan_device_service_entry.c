typedef struct _WWAN_DEVICE_SERVICE_ENTRY {
  GUID                                   DeviceServiceGuid;
  WWAN_DEVICE_SERVICE_SESSION_CAPABILITY SessionCapability;
  ULONG                                  uMaxSessionInstances;
} WWAN_DEVICE_SERVICE_ENTRY, *PWWAN_DEVICE_SERVICE_ENTRY;