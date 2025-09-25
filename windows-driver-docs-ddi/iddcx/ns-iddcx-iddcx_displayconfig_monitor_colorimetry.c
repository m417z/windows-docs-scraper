struct IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY {
  DISPLAYCONFIG_2DREGION                        RedPoint;
  DISPLAYCONFIG_2DREGION                        GreenPoint;
  DISPLAYCONFIG_2DREGION                        BluePoint;
  DISPLAYCONFIG_2DREGION                        WhitePoint;
  ULONG                                         MinLuminance;
  ULONG                                         MaxLuminance;
  ULONG                                         MaxFullFrameLuminance;
  IDDCX_WIRE_BITS_PER_COMPONENT                 BitsPerComponent;
  IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY_FLAGS Flags;
};