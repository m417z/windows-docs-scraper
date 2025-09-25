//Declaration

EVT_TR_CANCEL_SECURE_SERVICE_REQUEST EvtTrCancelSecureServiceRequest;

// Definition

VOID EvtTrCancelSecureServiceRequest
(
    WDFDEVICE ServiceDevice
    WDFOBJECT SessionContext
    PVOID RequestHandle
    PVOID * RequestContext
)
{...}