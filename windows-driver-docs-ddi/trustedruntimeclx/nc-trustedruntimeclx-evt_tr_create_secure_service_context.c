//Declaration

EVT_TR_CREATE_SECURE_SERVICE_CONTEXT EvtTrCreateSecureServiceContext;

// Definition

NTSTATUS EvtTrCreateSecureServiceContext
(
    WDFDEVICE MasterDevice
    LPCGUID ServiceGuid
    WDFDEVICE ServiceDevice
)
{...}