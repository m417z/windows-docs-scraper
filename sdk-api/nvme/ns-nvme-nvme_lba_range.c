typedef struct {
  NVME_CONTEXT_ATTRIBUTES Attributes;
  ULONG                   LogicalBlockCount;
  ULONGLONG               StartingLBA;
} NVME_LBA_RANGE, *PNVME_LBA_RANGE;