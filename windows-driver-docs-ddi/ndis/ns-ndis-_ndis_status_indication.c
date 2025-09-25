typedef struct _NDIS_STATUS_INDICATION {
  NDIS_OBJECT_HEADER Header;
  NDIS_HANDLE        SourceHandle;
  NDIS_PORT_NUMBER   PortNumber;
  NDIS_STATUS        StatusCode;
  ULONG              Flags;
  NDIS_HANDLE        DestinationHandle;
  PVOID              RequestId;
  PVOID              StatusBuffer;
  ULONG              StatusBufferSize;
  GUID               Guid;
  PVOID              NdisReserved[4];
} NDIS_STATUS_INDICATION, *PNDIS_STATUS_INDICATION;