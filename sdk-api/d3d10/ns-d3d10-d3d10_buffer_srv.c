typedef struct D3D10_BUFFER_SRV {
  union {
    UINT FirstElement;
    UINT ElementOffset;
  };
  union {
    UINT NumElements;
    UINT ElementWidth;
  };
} D3D10_BUFFER_SRV;