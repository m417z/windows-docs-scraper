typedef struct _ACCESS_RANGE {
  SCSI_PHYSICAL_ADDRESS RangeStart;
  ULONG                 RangeLength;
  BOOLEAN               RangeInMemory;
} ACCESS_RANGE, *PACCESS_RANGE;