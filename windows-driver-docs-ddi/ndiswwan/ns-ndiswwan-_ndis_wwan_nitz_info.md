# _NDIS_WWAN_NITZ_INFO structure

## Description

The **NDIS_WWAN_NITZ_INFO** structure describes the current network time and time zone information.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_NITZ_INFO** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_NITZ_INFO_REVISION_1 |
| Size | sizeof(NDIS_WWAN_NITZ_INFO) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of system capability. The following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | The operation succeeded. |
| WWAN_STATUS_BUSY | The operation failed because the device was busy. In the absence of any explicit information from the function to clear this condition, the host can use subsequent actions by the function (e.g. notifications or command completions) as a hint to retry the failed operation. |
| WWAN_STATUS_FAILURE | The operation failed. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | The operation failed because the device does not support this OID. |

### `NitzInfo`

A formatted [**WWAN_NITZ_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_nitz_info) structure that describes the current network time and time zone information.

## Remarks

This structure is used in the [NDIS_STATUS_WWAN_NITZ_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-nitz-info) status notification either in response to a previous [OID_WWAN_NITZ](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-nitz) Query request, or as an unsolicited notification.

## See also

[MB NITZ support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-nitz-support)

[OID_WWAN_NITZ](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-nitz)

[NDIS_STATUS_WWAN_NITZ_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-nitz-info)

[**WWAN_NITZ_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_nitz_info)