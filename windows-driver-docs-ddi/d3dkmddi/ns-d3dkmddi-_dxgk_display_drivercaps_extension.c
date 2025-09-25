typedef struct _DXGK_DISPLAY_DRIVERCAPS_EXTENSION {
  union {
    struct {
      UINT SecureDisplaySupport : 1;
      UINT VirtualModeSupport : 1;
#if ...
      UINT Reserved : 29;
      UINT NonSpecificPrimarySupport : 1;
      UINT HdrFP16ScanoutSupport : 1;
      UINT HdrARGB10ScanoutSupport : 1;
      UINT Hdr10MetadataSupport : 1;
      UINT VirtualRefreshRateSupport : 1;
      UINT SupportUsb4Targets : 1;
#elif
      UINT Reserved : 25;
#elif
      UINT Reserved : 26;
#elif
      UINT Reserved : 27;
#elif
      UINT Reserved : 28;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  };
} DXGK_DISPLAY_DRIVERCAPS_EXTENSION;