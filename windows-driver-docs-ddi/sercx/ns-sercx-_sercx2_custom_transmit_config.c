typedef struct _SERCX2_CUSTOM_TRANSMIT_CONFIG {
  ULONG   Size;
  ULONG   Alignment;
  ULONG   MinimumTransactionLength;
  ULONG   MaximumTransactionLength;
  ULONG   MinimumTransferUnit;
  BOOLEAN Exclusive;
} SERCX2_CUSTOM_TRANSMIT_CONFIG, *PSERCX2_CUSTOM_TRANSMIT_CONFIG;