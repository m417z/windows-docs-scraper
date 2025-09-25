typedef struct DXGI_HDR_METADATA_HDR10 {
  UINT16 RedPrimary[2];
  UINT16 GreenPrimary[2];
  UINT16 BluePrimary[2];
  UINT16 WhitePoint[2];
  UINT   MaxMasteringLuminance;
  UINT   MinMasteringLuminance;
  UINT16 MaxContentLightLevel;
  UINT16 MaxFrameAverageLightLevel;
} DXGI_HDR_METADATA_HDR10;