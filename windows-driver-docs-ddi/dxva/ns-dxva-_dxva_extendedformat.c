typedef struct _DXVA_ExtendedFormat {
  UINT                       SampleFormat : 8;
  UINT                       VideoChromaSubsampling : 4;
  DXVA_NominalRange          NominalRange : 3;
  DXVA_VideoTransferMatrix   VideoTransferMatrix : 3;
  DXVA_VideoLighting         VideoLighting : 4;
  DXVA_VideoPrimaries        VideoPrimaries : 5;
  DXVA_VideoTransferFunction VideoTransferFunction : 5;
} DXVA_ExtendedFormat;