typedef struct _DXVADDI_EXTENDEDFORMAT {
  union {
    struct {
      UINT SampleFormat : 8;
      UINT VideoChromaSubsampling : 4;
      UINT NominalRange : 3;
      UINT VideoTransferMatrix : 3;
      UINT VideoLighting : 4;
      UINT VideoPrimaries : 5;
      UINT VideoTransferFunction : 5;
    };
         UINT Value;
  };
} DXVADDI_EXTENDEDFORMAT;