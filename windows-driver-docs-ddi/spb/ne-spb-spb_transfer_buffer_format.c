typedef enum SPB_TRANSFER_BUFFER_FORMAT {
  SpbTransferBufferFormatInvalid,
  SpbTransferBufferFormatSimple,
  SpbTransferBufferFormatList,
  SpbTransferBufferFormatSimpleNonPaged,
  SpbTransferBufferFormatMdl,
  SpbTransferBufferFormatMax
}  *PSPB_TRANSFER_BUFFER_FORMAT;