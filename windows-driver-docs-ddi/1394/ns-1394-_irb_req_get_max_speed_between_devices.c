typedef struct _IRB_REQ_GET_MAX_SPEED_BETWEEN_DEVICES {
  ULONG          fulFlags;
  ULONG          ulNumberOfDestinations;
  PDEVICE_OBJECT hDestinationDeviceObjects[64];
  ULONG          fulSpeed;
} IRB_REQ_GET_MAX_SPEED_BETWEEN_DEVICES;