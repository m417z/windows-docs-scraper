typedef struct _DXGKARG_VALIDATEUPDATEALLOCPROPERTY {
  [in] HANDLE                           hAllocation;
  [in] UINT                             SupportedSegmentSet;
  [in] D3DDDI_SEGMENTPREFERENCE         PreferredSegment;
  [in] D3DDDI_UPDATEALLOCPROPERTY_FLAGS Flags;
  union {
    struct {
      UINT SetAccessedPhysically : 1;
      UINT SetSupportedSegmentSet : 1;
      UINT SetPreferredSegment : 1;
      UINT Reserved : 29;
    };
         UINT PropertyMaskValue;
  };
} DXGKARG_VALIDATEUPDATEALLOCPROPERTY;