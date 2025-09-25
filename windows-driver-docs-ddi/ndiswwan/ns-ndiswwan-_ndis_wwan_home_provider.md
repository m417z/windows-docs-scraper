# _NDIS_WWAN_HOME_PROVIDER structure

## Description

The NDIS_WWAN_HOME_PROVIDER structure represents details about the home network provider.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_HOME_PROVIDER structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_HOME_PROVIDER_REVISION_1 |
| Size | sizeof(NDIS_WWAN_HOME_PROVIDER) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the home provider operation. The following table shows the possible values for this
member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | Home provider operation succeeded. |
| WWAN_STATUS_PIN_REQUIRED | Home provider operation failed because the device requires a PIN. |
| WWAN_STATUS_SIM_NOT_INSERTED | Home provider operation failed because the SIM card was not inserted fully into the device. |
| WWAN_STATUS_READ_FAILURE | Home provider operation failed because the information could not be read from the device or SIM card. The error may be returned in instances where the SIM card does not have home provider information provisioned. |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation after the ready-state of the device changes to **WwanReadyStateInitialized**. |
| WWAN_STATUS_BAD_SIM | The operation failed because a bad SIM card was detected. |

### `Provider`

A formatted
[WWAN_PROVIDER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_provider2) object that represents details
about a network provider.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_PROVIDER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_provider2)