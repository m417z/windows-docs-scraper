//Declaration

EVT_TR_CREATE_SECURE_SERVICE_SESSION_CONTEXT EvtTrCreateSecureServiceSessionContext;

// Definition

NTSTATUS EvtTrCreateSecureServiceSessionContext
(
    WDFDEVICE ServiceDevice
    WDFOBJECT * SessionContextObject
)
{...}