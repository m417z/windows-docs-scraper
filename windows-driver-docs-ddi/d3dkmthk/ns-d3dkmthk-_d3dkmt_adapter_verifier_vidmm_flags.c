typedef union _D3DKMT_ADAPTER_VERIFIER_VIDMM_FLAGS {
  struct {
    UINT AlwaysRepatch : 1;
    UINT FailSharedPrimary : 1;
    UINT FailProbeAndLock : 1;
    UINT AlwaysDiscardOffer : 1;
    UINT NeverDiscardOffer : 1;
    UINT ForceComplexLock : 1;
    UINT NeverPrepatch : 1;
    UINT ExpectPreparationFailure : 1;
    UINT TakeSplitPoint : 1;
    UINT FailAcquireSwizzlingRange : 1;
    UINT PagingPathLockSubrange : 1;
    UINT PagingPathLockMinrange : 1;
    UINT FailVaRotation : 1;
    UINT NoDemotion : 1;
    UINT FailDefragPass : 1;
    UINT AlwaysProcessOfferList : 1;
    UINT AlwaysDecommitOffer : 1;
    UINT NeverMoveDefrag : 1;
    UINT AlwaysRelocateDisplayableResources : 1;
    UINT AlwaysFailGrowVPRMoves : 1;
    UINT NeverFlushTemporaryResources : 1;
    UINT AllocateTemporaryResourcesInAperture : 1;
    UINT Reserved : 10;
  };
  UINT32 Value;
} D3DKMT_ADAPTER_VERIFIER_VIDMM_FLAGS;