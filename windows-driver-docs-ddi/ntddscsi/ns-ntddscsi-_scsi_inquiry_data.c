typedef struct _SCSI_INQUIRY_DATA {
  UCHAR   PathId;
  UCHAR   TargetId;
  UCHAR   Lun;
  BOOLEAN DeviceClaimed;
  ULONG   InquiryDataLength;
  ULONG   NextInquiryDataOffset;
  UCHAR   InquiryData[1];
} SCSI_INQUIRY_DATA, *PSCSI_INQUIRY_DATA;