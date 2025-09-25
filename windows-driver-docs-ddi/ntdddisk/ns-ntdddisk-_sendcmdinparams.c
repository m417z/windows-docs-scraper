typedef struct _SENDCMDINPARAMS {
  ULONG   cBufferSize;
  IDEREGS irDriveRegs;
  UCHAR   bDriveNumber;
  UCHAR   bReserved[3];
  ULONG   dwReserved[4];
  UCHAR   bBuffer[1];
} SENDCMDINPARAMS, *PSENDCMDINPARAMS, *LPSENDCMDINPARAMS;