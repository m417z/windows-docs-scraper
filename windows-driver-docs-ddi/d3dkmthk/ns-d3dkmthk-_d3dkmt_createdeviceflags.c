typedef struct _D3DKMT_CREATEDEVICEFLAGS {
  UINT LegacyMode : 1;
  UINT RequestVSync : 1;
  UINT DisableGpuTimeout : 1;
  UINT TestDevice : 1;
#if ...
  UINT Reserved : 28;
#elif
  UINT Reserved : 29;
#else
  UINT Reserved : 30;
#endif
} D3DKMT_CREATEDEVICEFLAGS;