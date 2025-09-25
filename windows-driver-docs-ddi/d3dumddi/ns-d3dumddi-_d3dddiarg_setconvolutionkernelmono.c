typedef struct _D3DDDIARG_SETCONVOLUTIONKERNELMONO {
  [in] UINT  Width;
  [in] UINT  Height;
  [in] FLOAT *pKernelRow;
  [in] FLOAT *pKernelCol;
} D3DDDIARG_SETCONVOLUTIONKERNELMONO;