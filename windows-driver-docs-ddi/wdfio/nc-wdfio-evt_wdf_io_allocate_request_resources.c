EVT_WDF_IO_ALLOCATE_REQUEST_RESOURCES EvtWdfIoAllocateRequestResources;

NTSTATUS EvtWdfIoAllocateRequestResources(
  [in] WDFQUEUE Queue,
  [in] WDFREQUEST Request
)
{...}