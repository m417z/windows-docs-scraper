typedef struct HBA_FcpId {
  HBA_UINT32 FcId;
  HBA_WWN    NodeWWN;
  HBA_WWN    PortWWN;
  HBA_UINT64 FcpLun;
} HBA_FCPID, *PHBA_FCPID;