typedef struct {
  struct {
    UCHAR Result : 4;
    UCHAR CodeValue : 4;
  } Status;
  UCHAR     SegmentNumber;
  struct {
    UCHAR NSIDValid : 1;
    UCHAR FLBAValid : 1;
    UCHAR SCTValid : 1;
    UCHAR SCValid : 1;
    UCHAR Reserved : 4;
  } ValidDiagnostics;
  UCHAR     Reserved;
  ULONGLONG POH;
  ULONG     NSID;
  ULONGLONG FailingLBA;
  struct {
    UCHAR AdditionalInfo : 3;
    UCHAR Reserved : 5;
  } StatusCodeType;
  UCHAR     StatusCode;
  USHORT    VendorSpecific;
} NVME_DEVICE_SELF_TEST_RESULT_DATA, *PNVME_DEVICE_SELF_TEST_RESULT_DATA;