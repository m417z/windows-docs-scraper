# _NDIS_WWAN_PROVISIONED_CONTEXTS structure

## Description

The NDIS_WWAN_PROVISIONED_CONTEXTS structure represents a list of provisioned contexts and the number
of provisioned contexts in the list.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_PROVISIONED_CONTEXTS
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_PROVISIONED_CONTEXTS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_PROVISIONED_CONTEXTS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the provisioned context query or set operation. The following table shows the possible values for
this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | The operation succeeded. |
| WWAN_STATUS_FAILURE | The operation failed for a reason other than those listed here. |
| WWAN_STATUS_INVALID_PARAMETERS | The operation failed because of invalid parameters. |
| WWAN_STATUS_PIN_REQUIRED | The operation failed because the device requires a PIN. |
| WWAN_STATUS_BAD_SIM | The operation failed because a bad SIM card was detected. |
| WWAN_STATUS_SIM_NOT_INSERTED | The operation failed because the SIM card was not inserted fully into the device. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | The operation failed because the device does not support service activation. |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation after the ready-state of the device changes to **WwanReadyStateInitialized**. |
| WWAN_STATUS_READ_FAILURE | The operation failed because the device was unable to get provisioned contexts. |
| WWAN_STATUS_WRITE_FAILURE | The operation failed because the update request was unsuccessful. |

The status of provisioned context set operation. The following table shows the possible value for
this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_WRITE_FAILURE | The operation failed because the update request was unsuccessful. |

### `ContextListHeader`

A formatted
[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) object that represents a
list of provisioned contexts and the number of provisioned contexts in the list.

## Remarks

Miniport drivers should specify zero elements in the context list when they respond to
OID_WWAN_PROVISIONED_CONTEXT
*set* requests.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)