typedef struct _HWN_CLIENT_REGISTRATION_PACKET {
  USHORT                                Version;
  USHORT                                Size;
  ULONG                                 DeviceContextSize;
  ULONG                                 Reserved;
  PHWN_CLIENT_INITIALIZE_DEVICE         ClientInitializeDevice;
  PHWN_CLIENT_UNINITIALIZE_DEVICE       ClientUnInitializeDevice;
  PHWN_CLIENT_QUERY_DEVICE_INFORMATION  ClientQueryDeviceInformation;
  PHWN_CLIENT_START_DEVICE              ClientStartDevice;
  PHWN_CLIENT_STOP_DEVICE               ClientStopDevice;
  PHWN_CLIENT_SET_STATE                 ClientSetHwNState;
  PHWN_CLIENT_GET_STATE                 ClientGetHwNState;
} HWN_CLIENT_REGISTRATION_PACKET, HWN_CLIENT_REGISTRATION_PACKET;