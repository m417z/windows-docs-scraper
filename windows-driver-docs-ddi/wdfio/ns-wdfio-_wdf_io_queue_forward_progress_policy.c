typedef struct _WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY {
  ULONG                                              Size;
  ULONG                                              TotalForwardProgressRequests;
  WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY            ForwardProgressReservedPolicy;
  WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY_SETTINGS   ForwardProgressReservePolicySettings;
  PFN_WDF_IO_ALLOCATE_RESOURCES_FOR_RESERVED_REQUEST EvtIoAllocateResourcesForReservedRequest;
  PFN_WDF_IO_ALLOCATE_REQUEST_RESOURCES              EvtIoAllocateRequestResources;
} WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY, *PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY;