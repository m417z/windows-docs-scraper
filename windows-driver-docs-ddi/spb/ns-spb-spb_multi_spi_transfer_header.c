typedef struct SPB_MULTI_SPI_TRANSFER_HEADER {
  ULONG                       Size;
  SPB_MULTI_SPI_TRANSFER_MODE Mode;
  ULONG                       WritePhaseSingleSpiByteCount;
  ULONG                       WaitCycleByteCount;
} SPB_MULTI_SPI_TRANSFER_HEADER, *PSPB_MULTI_SPI_TRANSFER_HEADER;