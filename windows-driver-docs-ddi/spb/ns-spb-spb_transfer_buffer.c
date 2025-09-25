typedef struct SPB_TRANSFER_BUFFER {
  SPB_TRANSFER_BUFFER_FORMAT Format;
  union {
    SPB_TRANSFER_BUFFER_LIST_ENTRY Simple;
    struct {
      PSPB_TRANSFER_BUFFER_LIST_ENTRY List;
      ULONG                           ListCe;
    } BufferList;
    PMDL                           Mdl;
  };
} SPB_TRANSFER_BUFFER, *PSPB_TRANSFER_BUFFER;