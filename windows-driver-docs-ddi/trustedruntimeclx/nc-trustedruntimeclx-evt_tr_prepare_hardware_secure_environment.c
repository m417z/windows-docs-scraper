//Declaration

EVT_TR_PREPARE_HARDWARE_SECURE_ENVIRONMENT EvtTrPrepareHardwareSecureEnvironment;

// Definition

NTSTATUS EvtTrPrepareHardwareSecureEnvironment
(
    WDFDEVICE MasterDevice
    WDFCMRESLIST RawResources
    WDFCMRESLIST TranslatedResources
)
{...}