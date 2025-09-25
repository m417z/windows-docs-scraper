typedef struct _DXGK_ALLOCATIONUSAGEINFO1 {
  union {
    struct {
      UINT PrivateFormat : 1;
      UINT Swizzled : 1;
      UINT MipMap : 1;
      UINT Cube : 1;
      UINT Volume : 1;
      UINT Vertex : 1;
      UINT Index : 1;
      UINT Reserved : 25;
    };
          UINT Value;
  } Flags;
  union {
    [out] D3DDDIFORMAT Format;
    [out] UINT         PrivateFormat;
  };
  [out] UINT  SwizzledFormat;
  [out] UINT  ByteOffset;
  [out] UINT  Width;
  [out] UINT  Height;
  [out] UINT  Pitch;
  [out] UINT  Depth;
  [out] UINT  SlicePitch;
} DXGK_ALLOCATIONUSAGEINFO1;