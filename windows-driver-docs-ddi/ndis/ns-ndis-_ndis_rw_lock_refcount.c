typedef union _NDIS_RW_LOCK_REFCOUNT {
  ULONG RefCount;
  UCHAR cacheLine[16];
} NDIS_RW_LOCK_REFCOUNT;