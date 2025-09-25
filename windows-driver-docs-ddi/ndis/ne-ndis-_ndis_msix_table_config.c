typedef enum _NDIS_MSIX_TABLE_CONFIG {
  NdisMSIXTableConfigSetTableEntry,
  NdisMSIXTableConfigMaskTableEntry,
  NdisMSIXTableConfigUnmaskTableEntry,
  NdisMSIXTableConfigMax
} NDIS_MSIX_TABLE_OPERATION, *PNDIS_MSIX_TABLE_OPERATION;