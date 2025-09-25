typedef struct _D3DKMT_FLIPQUEUEINFO {
  [out] UINT                 MaxHardwareFlipQueueLength;
  [out] UINT                 MaxSoftwareFlipQueueLength;
  [out] D3DKMT_FLIPINFOFLAGS FlipFlags;
} D3DKMT_FLIPQUEUEINFO;