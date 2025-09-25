typedef struct FWPM_PROVIDER0_ {
  GUID               providerKey;
  FWPM_DISPLAY_DATA0 displayData;
  UINT32             flags;
  FWP_BYTE_BLOB      providerData;
  wchar_t            *serviceName;
} FWPM_PROVIDER0;