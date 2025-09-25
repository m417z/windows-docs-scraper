typedef struct D3D10DDIARG_BUFFER_SHADERRESOURCEVIEW {
  union {
         UINT FirstElement;
    [in] UINT ElementOffset;
  };
  union {
         UINT NumElements;
    [in] UINT ElementWidth;
  };
} D3D10DDIARG_BUFFER_SHADERRESOURCEVIEW;