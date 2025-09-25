typedef struct _DXGKMDT_OPM_ACP_AND_CGMSA_SIGNALING {
  DXGKMDT_OPM_RANDOM_NUMBER rnRandomNumber;
  ULONG                     ulStatusFlags;
  ULONG                     ulAvailableTVProtectionStandards;
  ULONG                     ulActiveTVProtectionStandard;
  ULONG                     ulReserved;
  ULONG                     ulAspectRatioValidMask1;
  ULONG                     ulAspectRatioData1;
  ULONG                     ulAspectRatioValidMask2;
  ULONG                     ulAspectRatioData2;
  ULONG                     ulAspectRatioValidMask3;
  ULONG                     ulAspectRatioData3;
  ULONG                     ulReserved2[4];
  ULONG                     ulReserved3[4];
} DXGKMDT_OPM_ACP_AND_CGMSA_SIGNALING;