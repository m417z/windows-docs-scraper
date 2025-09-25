typedef union _MF_MDL_SHARED_PAYLOAD_KEY {
  struct {
    ULONG   pHandle;
    ULONG   fHandle;
    ULONG64 uPayload;
  } combined;
  GUID   GMDLHandle;
} MF_MDL_SHARED_PAYLOAD_KEY, *PMF_MDL_SHARED_PAYLOAD_KEY;