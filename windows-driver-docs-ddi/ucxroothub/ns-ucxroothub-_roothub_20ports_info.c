typedef struct _ROOTHUB_20PORTS_INFO {
  ULONG                Size;
  USHORT               NumberOfPorts;
  USHORT               PortInfoSize;
  PROOTHUB_20PORT_INFO *PortInfoArray;
} ROOTHUB_20PORTS_INFO, *PROOTHUB_20PORTS_INFO;