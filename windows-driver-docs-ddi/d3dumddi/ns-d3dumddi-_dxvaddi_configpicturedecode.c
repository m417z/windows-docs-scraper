typedef struct _DXVADDI_CONFIGPICTUREDECODE {
  [in] GUID   guidConfigBitstreamEncryption;
  [in] GUID   guidConfigMBcontrolEncryption;
  [in] GUID   guidConfigResidDiffEncryption;
  [in] UINT   ConfigBitstreamRaw;
  [in] UINT   ConfigMBcontrolRasterOrder;
  [in] UINT   ConfigResidDiffHost;
  [in] UINT   ConfigSpatialResid8;
  [in] UINT   ConfigResid8Subtraction;
  [in] UINT   ConfigSpatialHost8or9Clipping;
  [in] UINT   ConfigSpatialResidInterleaved;
  [in] UINT   ConfigIntraResidUnsigned;
  [in] UINT   ConfigResidDiffAccelerator;
  [in] UINT   ConfigHostInverseScan;
  [in] UINT   ConfigSpecificIDCT;
  [in] UINT   Config4GroupedCoefs;
  [in] USHORT ConfigMinRenderTargetBuffCount;
  [in] USHORT ConfigDecoderSpecific;
} DXVADDI_CONFIGPICTUREDECODE;