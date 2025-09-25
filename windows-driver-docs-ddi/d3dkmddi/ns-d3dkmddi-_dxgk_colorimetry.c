typedef struct _DXGK_COLORIMETRY {
  D3DKMDT_2DOFFSET                   RedPoint;
  D3DKMDT_2DOFFSET                   GreenPoint;
  D3DKMDT_2DOFFSET                   BluePoint;
  D3DKMDT_2DOFFSET                   WhitePoint;
  ULONG                              MinLuminance;
  ULONG                              MaxLuminance;
  ULONG                              MaxFullFrameLuminance;
  D3DKMDT_WIRE_FORMAT_AND_PREFERENCE FormatBitDepths;
  DXGK_STANDARD_COLORIMETRY_FLAGS    StandardColorimetryFlags;
} DXGK_COLORIMETRY, *PDXGK_COLORIMETRY;