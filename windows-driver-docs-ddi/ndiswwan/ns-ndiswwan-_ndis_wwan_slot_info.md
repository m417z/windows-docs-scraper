# _NDIS_WWAN_SLOT_INFO structure

## Description

The **NDIS_WWAN_SLOT_INFO** structure represents the information about a slot in the modem of the MB device.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_SLOT_INFO** structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SLOT_INFO_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SLOT_INFO) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of system capability. The following table shows the possible values for
this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | The operation succeeded. |
| WWAN_STATUS_BUSY | The operation failed because the device was busy. In the absence of any explicit information from the function to clear this condition, the host can use subsequent actions by the function (e.g. notifications or command completions) as a hint to retry the failed operation. |
| WWAN_STATUS_FAILURE | The operation failed. |
| WWAN_STATUS_INVALID_PARAMETERS | The operation failed because of invalid parameters (e.g. slot numbers out of range). |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation when the ready-state is not **WwanReadyStateOff**. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | The operation failed because the device does not support this OID. |

### `SlotInfo`

A formatted [WWAN_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_slot_info) structure which represents the status of a slot in the modem.

## See also

[NDIS_STATUS_WWAN_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-slot-info-status)

[OID_WWAN_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-slot-info-status)

[WWAN_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_slot_info)