# WskQueryProviderCharacteristics function

## Description

The
**WskQueryProviderCharacteristics** function queries the range of WSK NPI versions supported by the WSK
subsystem.

## Parameters

### `WskRegistration` [in]

A pointer to the memory location initialized by
[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister) that identifies a WSK
application's registration instance.

### `WskProviderCharacteristics` [out]

A pointer to the range of WSK NPI versions supported by the WSK subsystem.

## Return value

**WskQueryProviderCharacteristics** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The query completed successfully. |
| **STATUS_DEVICE_NOT_READY** | The provider NPI was not yet available. |
| **Other status codes** | The query failed. |

## Remarks

WSK clients can use this function to determine the WSK NPI versions supported by the WSK
subsystem.

## See also

[WSK_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_characteristics)

[WSK_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_registration)