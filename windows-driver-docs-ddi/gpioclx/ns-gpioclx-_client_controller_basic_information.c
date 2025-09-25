typedef struct _CLIENT_CONTROLLER_BASIC_INFORMATION {
  USHORT                     Version;
  USHORT                     Size;
  USHORT                     TotalPins;
  UCHAR                      NumberOfPinsPerBank;
  ULONG                      DeviceIdleTimeout;
  CONTROLLER_ATTRIBUTE_FLAGS Flags;
} CLIENT_CONTROLLER_BASIC_INFORMATION, *PCLIENT_CONTROLLER_BASIC_INFORMATION;