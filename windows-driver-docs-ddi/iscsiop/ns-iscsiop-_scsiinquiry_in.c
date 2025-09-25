typedef struct _ScsiInquiry_IN {
  ULONGLONG UniqueSessionId;
  ULONGLONG Lun;
  UCHAR     InquiryFlags;
  UCHAR     PageCode;
} ScsiInquiry_IN, *PScsiInquiry_IN;