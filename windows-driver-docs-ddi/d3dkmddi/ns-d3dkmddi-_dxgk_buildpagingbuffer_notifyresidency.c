typedef struct _DXGK_BUILDPAGINGBUFFER_NOTIFYRESIDENCY {
  HANDLE                  hAllocation;
  D3DGPU_PHYSICAL_ADDRESS PhysicalAddress;
  union {
    UINT Resident : 1;
    UINT Reserved : 31;
  };
} DXGK_BUILDPAGINGBUFFER_NOTIFYRESIDENCY;