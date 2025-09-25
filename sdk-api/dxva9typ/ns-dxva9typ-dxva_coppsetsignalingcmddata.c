typedef struct _DXVA_COPPSetSignalingCmdData {
  ULONG ActiveTVProtectionStandard;
  ULONG AspectRatioChangeMask1;
  ULONG AspectRatioData1;
  ULONG AspectRatioChangeMask2;
  ULONG AspectRatioData2;
  ULONG AspectRatioChangeMask3;
  ULONG AspectRatioData3;
  ULONG ExtendedInfoChangeMask[4];
  ULONG ExtendedInfoData[4];
  ULONG Reserved;
} DXVA_COPPSetSignalingCmdData;