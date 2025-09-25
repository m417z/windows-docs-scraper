typedef struct _WHEA_RECOVERY_CONTEXT {
  union {
    struct {
      ULONG_PTR Address;
      BOOLEAN   Consumed;
      UINT16    ErrorCode;
      BOOLEAN   ErrorIpValid;
      BOOLEAN   RestartIpValid;
      BOOLEAN   ClearPoison;
    } MemoryError;
    struct {
      ULONG_PTR PmemErrInfo;
    } PmemError;
  };
  UINT64                           PartitionId;
  UINT32                           VpIndex;
  WHEA_RECOVERY_CONTEXT_ERROR_TYPE ErrorType;
  ULONG                            PageCount;
  WHEA_RECOVERY_CONTEXT_PAGE_INFO  PageInfo[WHEA_PFA_PAGE_RANGE_MAX];
} WHEA_RECOVERY_CONTEXT, *PWHEA_RECOVERY_CONTEXT;