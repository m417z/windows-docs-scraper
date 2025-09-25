typedef struct _DXVA_ConfigPictureDecode {
  DXVA_ConfigQueryOrReplyFunc dwFunction;
  DWORD                       dwReservedBits[3];
  GUID                        guidConfigBitstreamEncryption;
  GUID                        guidConfigMBcontrolEncryption;
  GUID                        guidConfigResidDiffEncryption;
  BYTE                        bConfigBitstreamRaw;
  BYTE                        bConfigMBcontrolRasterOrder;
  BYTE                        bConfigResidDiffHost;
  BYTE                        bConfigSpatialResid8;
  BYTE                        bConfigResid8Subtraction;
  BYTE                        bConfigSpatialHost8or9Clipping;
  BYTE                        bConfigSpatialResidInterleaved;
  BYTE                        bConfigIntraResidUnsigned;
  BYTE                        bConfigResidDiffAccelerator;
  BYTE                        bConfigHostInverseScan;
  BYTE                        bConfigSpecificIDCT;
  BYTE                        bConfig4GroupedCoefs;
} DXVA_ConfigPictureDecode, *LPDXVA_ConfigPictureDecode;