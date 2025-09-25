typedef struct DXGI_DDI_PRESENT_FLAGS {
  union {
    struct {
      UINT Blt : 1;
      UINT Flip : 1;
      UINT PreferRight : 1;
      UINT TemporaryMono : 1;
      UINT AllowTearing : 1;
      UINT AllowFlexibleRefresh : 1;
      UINT NoScanoutTransform : 1;
      UINT Reserved : 25;
    };
    UINT Value;
  };
} DXGI_DDI_PRESENT_FLAGS;