typedef struct _IO_BLOCK_EX {
  unsigned uOffset;
  unsigned uLength;
  PUCHAR   pbyData;
  unsigned uIndex;
  UCHAR    bRequest;
  UCHAR    bmRequestType;
  UCHAR    fTransferDirectionIn;
} IO_BLOCK_EX, *PIO_BLOCK_EX;