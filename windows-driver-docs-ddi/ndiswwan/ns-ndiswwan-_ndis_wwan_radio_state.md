# _NDIS_WWAN_RADIO_STATE structure

## Description

The NDIS_WWAN_RADIO_STATE structure represents the hardware-based and software-based radio power
states of the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_RADIO_STATE structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_RADIO_STATE_REVISION_1 |
| Size | sizeof(NDIS_WWAN_RADIO_STATE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the radio state operation. The following table shows the possible values for this
member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | Radio state operation succeeded. |
| WWAN_STATUS_BUSY | Radio state operation failed because the device is busy. |
| WWAN_STATUS_FAILURE | Radio state operation failed. |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation after the ready-state of the device changes to **WwanReadyStateInitialized**. |

### `RadioState`

A formatted
[WWAN_RADIO_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_radio_state) object that represents
the hardware-based and software-based radio power states of the device.

## Remarks

The miniport driver must set the
**uStatus** member to WWAN_STATUS_SUCCESS for unsolicited events (NDIS_STATUS_INDICATION::RequestId =
0).

Miniport drivers can set the
**uStatus** member to WWAN_STATUS_SUCCESS if the current radio state is the same as the requested
state.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_RADIO_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_radio_state)