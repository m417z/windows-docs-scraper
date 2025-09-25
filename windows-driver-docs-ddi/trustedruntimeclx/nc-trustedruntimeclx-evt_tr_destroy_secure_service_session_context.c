//Declaration

EVT_TR_DESTROY_SECURE_SERVICE_SESSION_CONTEXT EvtTrDestroySecureServiceSessionContext;

// Definition

NTSTATUS EvtTrDestroySecureServiceSessionContext
(
    WDFDEVICE ServiceDevice
    WDFOBJECT * SessionContextObject
)
{...}