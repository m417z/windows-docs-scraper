typedef struct _SERCX2_CUSTOM_RECEIVE_CONFIG {
  ULONG   Size;
  ULONG   Alignment;
  ULONG   MinimumTransactionLength;
  ULONG   MaximumTransactionLength;
  ULONG   MinimumTransferUnit;
  BOOLEAN Exclusive;
} SERCX2_CUSTOM_RECEIVE_CONFIG, *PSERCX2_CUSTOM_RECEIVE_CONFIG;