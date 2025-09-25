typedef struct _DXVA_COPPStatusSignalingCmdData {
  GUID  rApp;
  ULONG dwFlags;
  ULONG AvailableTVProtectionStandards;
  ULONG ActiveTVProtectionStandard;
  ULONG TVType;
  ULONG AspectRatioValidMask1;
  ULONG AspectRatioData1;
  ULONG AspectRatioValidMask2;
  ULONG AspectRatioData2;
  ULONG AspectRatioValidMask3;
  ULONG AspectRatioData3;
  ULONG ExtendedInfoValidMask[4];
  ULONG ExtendedInfoData[4];
} DXVA_COPPStatusSignalingCmdData;