typedef struct SPB_MULTI_SPI_TRANSFER {
  SPB_MULTI_SPI_TRANSFER_HEADER Header;
  ULONG                         TransferPhaseCount;
  SPB_TRANSFER_LIST_ENTRY       TransferPhases[1];
} SPB_MULTI_SPI_TRANSFER, *PSPB_MULTI_SPI_TRANSFER;