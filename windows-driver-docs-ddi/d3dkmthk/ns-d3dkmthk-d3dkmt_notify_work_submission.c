typedef struct _D3DKMT_NOTIFY_WORK_SUBMISSION {
  D3DKMT_HANDLE                       hHwQueue;
  D3DKMT_NOTIFY_WORK_SUBMISSION_FLAGS Flags;
  BYTE                                PrivateDriverData[D3DDDI_UMS_PDD_SIZE];
} D3DKMT_NOTIFY_WORK_SUBMISSION;