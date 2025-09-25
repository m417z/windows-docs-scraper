typedef struct _DXVAHD_VPCAPS {
  GUID VPGuid;
  UINT PastFrames;
  UINT FutureFrames;
  UINT ProcessorCaps;
  UINT ITelecineCaps;
  UINT CustomRateCount;
} DXVAHD_VPCAPS;