typedef struct _NDIS_PORT {
  PNDIS_PORT                Next;
  PVOID                     NdisReserved;
  PVOID                     MiniportReserved;
  PVOID                     ProtocolReserved;
  NDIS_PORT_CHARACTERISTICS PortCharacteristics;
} NDIS_PORT, *PNDIS_PORT;