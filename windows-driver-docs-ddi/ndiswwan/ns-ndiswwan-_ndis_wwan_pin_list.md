# _NDIS_WWAN_PIN_LIST structure

## Description

The NDIS_WWAN_PIN_LIST structure represents a list of descriptions of Personal Identification Numbers
(PINs).

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_PIN_LIST structure. The
MB Service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_PIN_LIST_REVISION_1 |
| Size | sizeof(NDIS_WWAN_PIN_LIST) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the PIN list operation. The following table shows the possible values for this.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | The PIN list operation succeeded. |
| WWAN_STATUS_FAILURE | The PIN list operation failed. |
| WWAN_STATUS_PIN_REQUIRED | The PIN list operation failed because a PIN must be entered before this operation can proceed. |
| WWAN_STATUS_SIM_NOT_INSERTED | The PIN list operation failed because the SIM card is not inserted. |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation after the ready-state of the device changes to **WwanReadyStateInitialized**. |
| WWAN_STATUS_BAD_SIM | The operation failed because a bad SIM card was detected. |

### `PinList`

A formatted
[WWAN_PIN_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_list) object that represents a list
of descriptions of Personal Identification Numbers (PINs).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_PIN_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_list)