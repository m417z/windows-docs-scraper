typedef struct _DXGK_ALLOCATIONINFOFLAGS2 {
  union {
    struct {
      UINT ShareBackingStoreWithKmd : 1;
      UINT NoImplicitSynchronization : 1;
      UINT DisablePartialResidency : 1;
      UINT RestrictedToSingleSegment : 1;
      UINT NeedPagingVaAtResidencyNotification : 1;
      UINT Reserved01 : 1;
      UINT FaultAndStall : 1;
#if ...
      UINT Reserved : 25;
#else
      UINT Reserved : 31;
#endif
    };
    UINT Value;
  };
} DXGK_ALLOCATIONINFOFLAGS2;