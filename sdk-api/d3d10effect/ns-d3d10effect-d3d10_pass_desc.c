typedef struct _D3D10_PASS_DESC {
  LPCSTR Name;
  UINT   Annotations;
  BYTE   *pIAInputSignature;
  SIZE_T IAInputSignatureSize;
  UINT   StencilRef;
  UINT   SampleMask;
  FLOAT  BlendFactor[4];
} D3D10_PASS_DESC;