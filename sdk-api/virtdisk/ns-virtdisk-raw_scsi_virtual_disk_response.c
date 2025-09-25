typedef struct _RAW_SCSI_VIRTUAL_DISK_RESPONSE {
  RAW_SCSI_VIRTUAL_DISK_VERSION Version;
  union {
    struct {
      UCHAR ScsiStatus;
      UCHAR SenseInfoLength;
      ULONG DataTransferLength;
    } Version1;
  };
} RAW_SCSI_VIRTUAL_DISK_RESPONSE, *PRAW_SCSI_VIRTUAL_DISK_RESPONSE;