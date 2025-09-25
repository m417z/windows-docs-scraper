typedef struct _D3DKMT_VIDMM_ESCAPE {
  D3DKMT_VIDMMESCAPETYPE Type;
  union {
    struct {
      union {
        struct {
          ULONG ProbeAndLock : 1;
          ULONG SplitPoint : 1;
          ULONG NoDemotion : 1;
          ULONG SwizzlingAperture : 1;
          ULONG PagingPathLockSubRange : 1;
          ULONG PagingPathLockMinRange : 1;
          ULONG ComplexLock : 1;
          ULONG FailVARotation : 1;
          ULONG NoWriteCombined : 1;
          ULONG NoPrePatching : 1;
          ULONG AlwaysRepatch : 1;
          ULONG ExpectPreparationFailure : 1;
          ULONG FailUserModeVAMapping : 1;
          ULONG NeverDiscardOfferedAllocation : 1;
          ULONG AlwaysDiscardOfferedAllocation : 1;
#if ...
          ULONG Reserved : 17;
#else
          ULONG Reserved : 19;
#endif
        };
        ULONG Value;
      };
    } SetFault;
    struct {
      D3DKMT_HANDLE ResourceHandle;
      D3DKMT_HANDLE AllocationHandle;
      HANDLE        hProcess;
    } Evict;
    struct {
      D3DKMT_ALIGN64 UINT64 NtHandle;
    } EvictByNtHandle;
    struct {
      union {
        struct {
          UINT NumVads;
        } GetNumVads;
        D3DKMT_VAD_DESC         GetVad;
        D3DKMT_VA_RANGE_DESC    GetVadRange;
        D3DKMT_GET_GPUMMU_CAPS  GetGpuMmuCaps;
        D3DKMT_GET_PTE          GetPte;
        D3DKMT_GET_SEGMENT_CAPS GetSegmentCaps;
      };
      D3DKMT_VAD_ESCAPE_COMMAND Command;
      NTSTATUS                  Status;
      union {
        D3DKMT_GET_PTE_EXT GetPteExt;
      };
    } GetVads;
    struct {
      D3DKMT_ALIGN64 ULONGLONG LocalMemoryBudget;
      D3DKMT_ALIGN64 ULONGLONG SystemMemoryBudget;
    } SetBudget;
    struct {
      HANDLE hProcess;
      BOOL   bAllowWakeOnSubmission;
    } SuspendProcess;
    struct {
      HANDLE hProcess;
    } ResumeProcess;
    struct {
      D3DKMT_ALIGN64 UINT64 NumBytesToTrim;
    } GetBudget;
    struct {
      ULONG MinTrimInterval;
      ULONG MaxTrimInterval;
      ULONG IdleTrimInterval;
    } SetTrimIntervals;
    D3DKMT_EVICTION_CRITERIA EvictByCriteria;
    struct {
      BOOL bFlush;
    } Wake;
    struct {
      D3DKMT_DEFRAG_ESCAPE_OPERATION Operation;
      UINT                           SegmentId;
      D3DKMT_ALIGN64 ULONGLONG       TotalCommitted;
      D3DKMT_ALIGN64 ULONGLONG       TotalFree;
      D3DKMT_ALIGN64 ULONGLONG       LargestGapBefore;
      D3DKMT_ALIGN64 ULONGLONG       LargestGapAfter;
    } Defrag;
    struct {
      D3DKMT_HANDLE            hPagingQueue;
      UINT                     PhysicalAdapterIndex;
      ULONG                    Milliseconds;
      D3DKMT_ALIGN64 ULONGLONG PagingFenceValue;
    } DelayExecution;
    struct {
      UINT16 PhysicalAdapterIndex;
      UINT16 SegmentId;
    } VerifyIntegrity;
    struct {
      D3DKMT_ALIGN64 LONGLONG TimerValue;
    } DelayedEvictionConfig;
  };
} D3DKMT_VIDMM_ESCAPE;