typedef struct _NDIS_OID_REQUEST {
  NDIS_OBJECT_HEADER       Header;
  NDIS_REQUEST_TYPE        RequestType;
  NDIS_PORT_NUMBER         PortNumber;
  UINT                     Timeout;
  PVOID                    RequestId;
  NDIS_HANDLE              RequestHandle;
  union {
    NDIS_OID Oid;
    struct {
      NDIS_OID Oid;
      PVOID    InformationBuffer;
      UINT     InformationBufferLength;
      UINT     BytesWritten;
      UINT     BytesNeeded;
    } QUERY_INFORMATION;
    struct {
      NDIS_OID Oid;
      PVOID    InformationBuffer;
      UINT     InformationBufferLength;
      UINT     BytesRead;
      UINT     BytesNeeded;
    } SET_INFORMATION;
    struct {
      NDIS_OID Oid;
      PVOID    InformationBuffer;
      ULONG    InputBufferLength;
      ULONG    OutputBufferLength;
      ULONG    MethodId;
      UINT     BytesWritten;
      UINT     BytesRead;
      UINT     BytesNeeded;
    } METHOD_INFORMATION;
  } DATA;
  _REQUEST_DATA            _REQUEST_DATA;
  UCHAR                    *NdisReserved[NDIS_OID_REQUEST_NDIS_RESERVED_SIZE  sizeof(PVOID)];
  UCHAR                    *MiniportReserved[2  sizeof(PVOID)];
  UCHAR                    *SourceReserved[2  sizeof(PVOID)];
  UCHAR                    SupportedRevision;
  UCHAR                    Reserved1;
  USHORT                   Reserved2;
  NDIS_NIC_SWITCH_ID       SwitchId;
  NDIS_NIC_SWITCH_VPORT_ID VPortId;
  ULONG                    Flags;
} NDIS_OID_REQUEST, *PNDIS_OID_REQUEST;