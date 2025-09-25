typedef struct SPB_TRANSFER_LIST {
  ULONG                   Size;
  ULONG                   Reserved;
  ULONG                   TransferCount;
  SPB_TRANSFER_LIST_ENTRY Transfers[1];
} SPB_TRANSFER_LIST, *PSPB_TRANSFER_LIST;