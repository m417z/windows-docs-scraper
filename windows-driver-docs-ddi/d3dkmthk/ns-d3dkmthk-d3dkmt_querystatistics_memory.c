typedef struct _D3DKMT_QUERYSTATISTICS_MEMORY {
  D3DKMT_ALIGN64 ULONGLONG TotalBytesEvicted;
  ULONG                    AllocsCommitted;
  ULONG                    AllocsResident;
} D3DKMT_QUERYSTATISTICS_MEMORY;