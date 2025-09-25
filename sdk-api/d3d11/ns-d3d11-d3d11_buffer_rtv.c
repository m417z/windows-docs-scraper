typedef struct D3D11_BUFFER_RTV {
  union {
    UINT FirstElement;
    UINT ElementOffset;
  };
  union {
    UINT NumElements;
    UINT ElementWidth;
  };
} D3D11_BUFFER_RTV;