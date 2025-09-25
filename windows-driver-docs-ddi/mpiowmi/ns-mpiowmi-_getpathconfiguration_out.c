typedef struct _GetPathConfiguration_OUT {
  ULONG     EntryCount;
  SCSI_ADDR Address[1];
} GetPathConfiguration_OUT, *PGetPathConfiguration_OUT;