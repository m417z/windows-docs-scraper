typedef struct _NDIS_MSIX_CONFIG_PARAMETERS {
  NDIS_OBJECT_HEADER        Header;
  NDIS_MSIX_TABLE_OPERATION ConfigOperation;
  ULONG                     TableEntry;
  ULONG                     MessageNumber;
} NDIS_MSIX_CONFIG_PARAMETERS, *PNDIS_MSIX_CONFIG_PARAMETERS;