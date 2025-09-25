typedef struct _AVC_PEER_DO_LOCATOR {
  NODE_ADDRESS   NodeAddress;
  ULONG          Generation;
  PDEVICE_OBJECT DeviceObject;
} AVC_PEER_DO_LOCATOR, *PAVC_PEER_DO_LOCATOR;