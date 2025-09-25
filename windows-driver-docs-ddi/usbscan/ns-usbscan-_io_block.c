typedef struct _IO_BLOCK {
  unsigned uOffset;
  unsigned uLength;
  PUCHAR   pbyData;
  unsigned uIndex;
} IO_BLOCK, *PIO_BLOCK;