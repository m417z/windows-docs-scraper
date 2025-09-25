typedef struct _D3DKMT_CREATEALLOCATIONFLAGS {
  UINT CreateResource : 1;
  UINT CreateShared : 1;
  UINT NonSecure : 1;
  UINT CreateProtected : 1;
  UINT RestrictSharedAccess : 1;
  UINT ExistingSysMem : 1;
  UINT NtSecuritySharing : 1;
  UINT ReadOnly : 1;
  UINT CreateWriteCombined : 1;
  UINT CreateCached : 1;
  UINT SwapChainBackBuffer : 1;
  UINT CrossAdapter : 1;
  UINT OpenCrossAdapter : 1;
  UINT PartialSharedCreation : 1;
  UINT Zeroed : 1;
  UINT WriteWatch : 1;
  UINT StandardAllocation : 1;
  UINT ExistingSection : 1;
  UINT AllowNotZeroed : 1;
  UINT PhysicallyContiguous : 1;
  UINT NoKmdAccess : 1;
  UINT SharedDisplayable : 1;
  UINT NoImplicitSynchronization : 1;
#if ...
  UINT Reserved : 9;
#elif
  UINT Reserved : 10;
#elif
  UINT Reserved : 11;
#elif
  UINT Reserved : 13;
#elif
  UINT Reserved : 14;
#elif
  UINT Reserved : 16;
#elif
  UINT Reserved : 21;
#else
  UINT Reserved : 26;
#endif
} D3DKMT_CREATEALLOCATIONFLAGS;