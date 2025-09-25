typedef struct _UFX_DEVICE_CAPABILITIES {
  ULONG            Size;
  USB_DEVICE_SPEED MaxSpeed;
  ULONG            RemoteWakeSignalDelay;
  BOOLEAN          PdcpSupported;
  USHORT           InEndpointBitmap;
  USHORT           OutEndpointBitmap;
  BOOLEAN          SharesConnectors;
  ULONG            GroupId;
} UFX_DEVICE_CAPABILITIES, *PUFX_DEVICE_CAPABILITIES;