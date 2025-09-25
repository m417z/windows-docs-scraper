typedef struct _ROOTHUB_30PORTS_INFO {
  ULONG                Size;
  USHORT               NumberOfPorts;
  USHORT               PortInfoSize;
  PROOTHUB_30PORT_INFO *PortInfoArray;
} ROOTHUB_30PORTS_INFO, *PROOTHUB_30PORTS_INFO;