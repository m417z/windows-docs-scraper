typedef struct D3D11_1DDI_VIDEO_PROCESSOR_COLOR_SPACE {
       UINT Usage : 1;
       UINT RGB_Range : 1;
       UINT YCbCr_Matrix : 1;
       UINT YCbCr_xvYCC : 1;
  [in] UINT Nominal_Range : 2;
       UINT Reserved : 26;
} D3D11_1DDI_VIDEO_PROCESSOR_COLOR_SPACE;