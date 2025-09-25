typedef struct SPB_TRANSFER_DESCRIPTOR {
  USHORT                 Size;
  SPB_TRANSFER_DIRECTION Direction;
  size_t                 TransferLength;
  ULONG                  DelayInUs;
} SPB_TRANSFER_DESCRIPTOR, *PSPB_TRANSFER_DESCRIPTOR;