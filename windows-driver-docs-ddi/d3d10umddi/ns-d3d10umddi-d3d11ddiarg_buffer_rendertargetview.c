typedef struct D3D11DDIARG_BUFFER_RENDERTARGETVIEW {
  union {
    [in] UINT FirstElement;
    [in] UINT ElementOffset;
  };
  union {
    [in] UINT NumElements;
    [in] UINT ElementWidth;
  };
} D3D11DDIARG_BUFFER_RENDERTARGETVIEW;