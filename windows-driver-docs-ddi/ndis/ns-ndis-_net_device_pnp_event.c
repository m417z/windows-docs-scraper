typedef struct _NET_DEVICE_PNP_EVENT {
  NDIS_OBJECT_HEADER    Header;
  NDIS_PORT_NUMBER      PortNumber;
  NDIS_DEVICE_PNP_EVENT DevicePnPEvent;
  PVOID                 InformationBuffer;
  ULONG                 InformationBufferLength;
  UCHAR                 *NdisReserved[2  sizeof(PVOID)];
} NET_DEVICE_PNP_EVENT, *PNET_DEVICE_PNP_EVENT;