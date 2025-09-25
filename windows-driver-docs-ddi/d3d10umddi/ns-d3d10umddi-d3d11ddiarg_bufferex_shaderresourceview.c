typedef struct D3D11DDIARG_BUFFEREX_SHADERRESOURCEVIEW {
  union {
    [in] UINT FirstElement;
    [in] UINT ElementOffset;
  };
  union {
    [in] UINT NumElements;
    [in] UINT ElementWidth;
  };
  [in] UINT  Flags;
} D3D11DDIARG_BUFFEREX_SHADERRESOURCEVIEW;