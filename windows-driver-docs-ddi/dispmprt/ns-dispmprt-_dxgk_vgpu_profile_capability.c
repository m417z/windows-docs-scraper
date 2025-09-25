typedef struct _DXGK_VGPU_PROFILE_CAPABILITY {
  UINT64 TotalValue;
  UINT64 AvailableValue;
  UINT64 MinPartitionValue;
  UINT64 MaxPartitionValue;
  UINT64 OptimalPartitionValue;
} DXGK_VGPU_PROFILE_CAPABILITY, *PDXGK_VGPU_PROFILE_CAPABILITY;