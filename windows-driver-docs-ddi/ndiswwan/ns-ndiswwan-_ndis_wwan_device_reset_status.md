# _NDIS_WWAN_DEVICE_RESET_STATUS structure

## Description

The **NDIS_WWAN_DEVICE_RESET_STATUS** structure represents a modem device's reset status. It is sent to the MB host in the [NDIS_STATUS_WWAN_DEVICE_RESET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-device-reset-status) notification in an asynchronous response to an [OID_WWAN_DEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-reset) set request.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_DEVICE_RESET_STATUS** structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_DEVICE_RESET_STATUS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_DEVICE_RESET_STATUS) |

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
| WWAN_STATUS_NO_DEVICE_SUPPORT | The operation failed because the device does not support this OID. |

## See also

[MB modem reset operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-modem-reset-operations)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_STATUS_WWAN_DEVICE_RESET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-device-reset-status)

[OID_WWAN_DEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-reset)