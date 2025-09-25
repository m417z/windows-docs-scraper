//Declaration

EVT_TR_QUERY_SERVICE_CALLBACKS EvtTrQueryServiceCallbacks;

// Definition

PTR_SECURE_SERVICE_CALLBACKS EvtTrQueryServiceCallbacks
(
    WDFDEVICE MasterDevice
    LPGUID ServiceGuid
)
{...}