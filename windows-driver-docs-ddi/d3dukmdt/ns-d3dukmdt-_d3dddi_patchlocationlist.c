typedef struct _D3DDDI_PATCHLOCATIONLIST {
  [in]     UINT  AllocationIndex;
  union {
    struct {
      UINT SlotId : 24;
      UINT Reserved : 8;
    };
    [in]     UINT Value;
  };
  [in/out] UINT  DriverId;
  [in/out] UINT  AllocationOffset;
  [in/out] UINT  PatchOffset;
  [in/out] UINT  SplitOffset;
} D3DDDI_PATCHLOCATIONLIST;