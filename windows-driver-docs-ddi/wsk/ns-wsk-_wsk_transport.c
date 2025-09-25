typedef struct _WSK_TRANSPORT {
  USHORT         Version;
  USHORT         SocketType;
  ULONG          Protocol;
  ADDRESS_FAMILY AddressFamily;
  GUID           ProviderId;
} WSK_TRANSPORT, *PWSK_TRANSPORT;