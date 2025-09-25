typedef struct _RAW_SCSI_VIRTUAL_DISK_PARAMETERS {
  RAW_SCSI_VIRTUAL_DISK_VERSION Version;
  union {
    struct {
      BOOL  RSVDHandle;
      UCHAR DataIn;
      UCHAR CdbLength;
      UCHAR SenseInfoLength;
      ULONG SrbFlags;
      ULONG DataTransferLength;
      PVOID DataBuffer;
      UCHAR *SenseInfo;
      UCHAR *Cdb;
    } Version1;
  };
} RAW_SCSI_VIRTUAL_DISK_PARAMETERS, *PRAW_SCSI_VIRTUAL_DISK_PARAMETERS;