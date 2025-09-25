typedef struct D3D10_BUFFER_RTV {
  union {
    UINT FirstElement;
    UINT ElementOffset;
  };
  union {
    UINT NumElements;
    UINT ElementWidth;
  };
} D3D10_BUFFER_RTV;