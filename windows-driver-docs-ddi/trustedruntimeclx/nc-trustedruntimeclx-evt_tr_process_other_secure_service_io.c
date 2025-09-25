//Declaration

EVT_TR_PROCESS_OTHER_SECURE_SERVICE_IO EvtTrProcessOtherSecureServiceIo;

// Definition

VOID EvtTrProcessOtherSecureServiceIo
(
    WDFDEVICE ServiceDevice
    WDFOBJECT SessionContext
    WDFREQUEST Request
)
{...}