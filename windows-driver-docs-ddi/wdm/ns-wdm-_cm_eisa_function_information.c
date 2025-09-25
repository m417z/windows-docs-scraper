typedef struct _CM_EISA_FUNCTION_INFORMATION {
  ULONG                     CompressedId;
  UCHAR                     IdSlotFlags1;
  UCHAR                     IdSlotFlags2;
  UCHAR                     MinorRevision;
  UCHAR                     MajorRevision;
  UCHAR                     Selections[26];
  UCHAR                     FunctionFlags;
  UCHAR                     TypeString[80];
  EISA_MEMORY_CONFIGURATION EisaMemory[9];
  EISA_IRQ_CONFIGURATION    EisaIrq[7];
  EISA_DMA_CONFIGURATION    EisaDma[4];
  EISA_PORT_CONFIGURATION   EisaPort[20];
  UCHAR                     InitializationData[60];
} CM_EISA_FUNCTION_INFORMATION, *PCM_EISA_FUNCTION_INFORMATION;