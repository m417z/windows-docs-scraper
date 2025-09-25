typedef struct _DXVA_Status_AV1 {
  UINT              StatusReportFeedbackNumber;
  DXVA_PicEntry_AV1 CurrPic;
  UCHAR             BufType;
  UCHAR             Status;
  UCHAR             Reserved8Bits;
  USHORT            NumMbsAffected;
} DXVA_Status_AV1, *LPDXVA_Status_AV1;