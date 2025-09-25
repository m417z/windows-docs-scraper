typedef struct _WSK_TDI_MAP {
  USHORT         SocketType;
  ADDRESS_FAMILY AddressFamily;
  ULONG          Protocol;
  PCWSTR         TdiDeviceName;
} WSK_TDI_MAP, *PWSK_TDI_MAP;