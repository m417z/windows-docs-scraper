typedef struct _WWAN_SUPPORTED_DEVICE_SERVICES {
  ULONG            uMaxCommandDataSize;
  ULONG            uMaxSessionDataSize;
  ULONG            uMaxSessionCount;
  WWAN_LIST_HEADER ListHeader;
} WWAN_SUPPORTED_DEVICE_SERVICES, *PWWAN_SUPPORTED_DEVICE_SERVICES;