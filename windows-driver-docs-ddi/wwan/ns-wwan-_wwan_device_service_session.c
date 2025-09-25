typedef struct _WWAN_DEVICE_SERVICE_SESSION {
  GUID                              DeviceServiceGuid;
  WWAN_DEVICE_SERVICE_SESSION_STATE State;
  ULONG                             uSessionID;
} WWAN_DEVICE_SERVICE_SESSION, *PWWAN_DEVICE_SERVICE_SESSION;