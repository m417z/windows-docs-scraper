typedef union _D3DKMDT_WIRE_FORMAT_AND_PREFERENCE {
  struct {
    D3DKMDT_MODE_PREFERENCE Preference : 2;
    UINT                    Rgb : 6;
    UINT                    YCbCr444 : 6;
    UINT                    YCbCr422 : 6;
    UINT                    YCbCr420 : 6;
    UINT                    Intensity : 6;
  };
  UINT   Value;
} D3DKMDT_WIRE_FORMAT_AND_PREFERENCE, *PD3DKMDT_WIRE_FORMAT_AND_PREFERENCE;