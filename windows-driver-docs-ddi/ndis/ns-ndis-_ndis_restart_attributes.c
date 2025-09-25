typedef struct _NDIS_RESTART_ATTRIBUTES {
  PNDIS_RESTART_ATTRIBUTES Next;
  NDIS_OID                 Oid;
  ULONG                    DataLength;
  UCHAR                    Data[1];
} NDIS_RESTART_ATTRIBUTES, *PNDIS_RESTART_ATTRIBUTES;