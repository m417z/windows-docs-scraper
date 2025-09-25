//Declaration

EVT_TR_ENUMERATE_SECURE_SERVICES EvtTrEnumerateSecureServices;

// Definition

NTSTATUS EvtTrEnumerateSecureServices
(
    WDFDEVICE MasterDevice
    ULONG Index
    PUCHAR SecureServiceDescription
    ULONG * DescriptionSize
)
{...}