typedef struct {
  struct {
    UCHAR Status : 4;
    UCHAR Reserved : 4;
  } CurrentOperation;
  struct {
    UCHAR CompletePercent : 7;
    UCHAR Reserved : 1;
  } CurrentCompletion;
  UCHAR                             Reserved[2];
  NVME_DEVICE_SELF_TEST_RESULT_DATA ResultData[20];
} NVME_DEVICE_SELF_TEST_LOG, *PNVME_DEVICE_SELF_TEST_LOG;