typedef struct _DXGK_PTE {
  union {
    struct {
      ULONGLONG Valid : 1;
      ULONGLONG Zero : 1;
      ULONGLONG CacheCoherent : 1;
      ULONGLONG ReadOnly : 1;
      ULONGLONG NoExecute : 1;
      ULONGLONG Segment : 5;
      ULONGLONG LargePage : 1;
      ULONGLONG PhysicalAdapterIndex : 6;
      ULONGLONG PageTablePageSize : 2;
      ULONGLONG SystemReserved0 : 1;
      ULONGLONG Reserved : 44;
    };
    ULONGLONG Flags;
  };
  union {
    ULONGLONG PageAddress;
    ULONGLONG PageTableAddress;
  };
} DXGK_PTE;