//Declaration

EVT_TR_PROCESS_SECURE_SERVICE_REQUEST EvtTrProcessSecureServiceRequest;

// Definition

NTSTATUS EvtTrProcessSecureServiceRequest
(
    WDFDEVICE ServiceDevice
    WDFOBJECT SessionContext
    PVOID RequestHandle
    KPRIORITY Priority
    PTR_SERVICE_REQUEST Request
    ULONG Flags
    PULONG_PTR BytesWritten
    PVOID * RequestContext
)
{...}