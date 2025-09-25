typedef struct {
  ULONG Reserved0;
  UCHAR AvailableSpareThreshold;
  UCHAR PercentageUsed;
  UCHAR Reserved1[26];
  UCHAR EnduranceEstimate[16];
  UCHAR DataUnitsRead[16];
  UCHAR DataUnitsWritten[16];
  UCHAR MediaUnitsWritten[16];
  UCHAR Reserved2[416];
} NVME_ENDURANCE_GROUP_LOG, *PNVME_ENDURANCE_GROUP_LOG;