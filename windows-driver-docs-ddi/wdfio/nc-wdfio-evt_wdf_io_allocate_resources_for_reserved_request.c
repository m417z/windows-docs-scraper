EVT_WDF_IO_ALLOCATE_RESOURCES_FOR_RESERVED_REQUEST EvtWdfIoAllocateResourcesForReservedRequest;

NTSTATUS EvtWdfIoAllocateResourcesForReservedRequest(
  [in] WDFQUEUE Queue,
  [in] WDFREQUEST Request
)
{...}