typedef struct _DXVAHDDDI_VPCAPS {
  [out] GUID VPGuid;
  [out] UINT PastFrames;
  [out] UINT FutureFrames;
  [out] UINT ProcessorCaps;
  [out] UINT ITelecineCaps;
  [out] UINT CustomRateCount;
} DXVAHDDDI_VPCAPS;