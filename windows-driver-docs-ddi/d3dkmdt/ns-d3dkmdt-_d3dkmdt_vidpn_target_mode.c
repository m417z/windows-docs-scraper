typedef struct _D3DKMDT_VIDPN_TARGET_MODE {
  D3DKMDT_VIDEO_PRESENT_TARGET_MODE_ID Id;
  D3DKMDT_VIDEO_SIGNAL_INFO            VideoSignalInfo;
  union {
    D3DKMDT_WIRE_FORMAT_AND_PREFERENCE WireFormatAndPreference;
    struct {
      D3DKMDT_MODE_PREFERENCE Preference : 2;
    };
  };
  D3DKMDT_MODE_PREFERENCE              Preference;
  D3DDDI_RATIONAL                      MinimumVSyncFreq;
} D3DKMDT_VIDPN_TARGET_MODE;