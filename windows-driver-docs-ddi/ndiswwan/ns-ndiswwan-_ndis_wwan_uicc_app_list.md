# _NDIS_WWAN_UICC_APP_LIST structure

## Description

The **NDIS_WWAN_UICC_APP_LIST** structure describes a list of applications in a UICC and information about them.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_UICC_APP_LIST** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_UICC_APP_LIST_REVISION_1 |
| Size | sizeof(NDIS_WWAN_UICC_APP_LIST) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of system capability. The following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | The operation succeeded. |
| WWAN_STATUS_BUSY | The operation failed because the device was busy. In the absence of any explicit information from the function to clear this condition, the host can use subsequent actions by the function (e.g. notifications or command completions) as a hint to retry the failed operation. |
| WWAN_STATUS_FAILURE | The operation failed. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | The operation failed because the device does not support this OID. |

### `UiccAppList`

A formatted [**WWAN_UICC_APP_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_app_list) structure that describes the list of applications in the UICC, and information about them.

## Remarks

This structure is used in the [NDIS_STATUS_WWAN_UICC_APP_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-uicc-app-list) status notification in response to a previous [OID_WWAN_UICC_APP_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-app-list) Query request.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_APP_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-app-list)

[NDIS_STATUS_WWAN_UICC_APP_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-uicc-app-list)

[**WWAN_UICC_APP_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_app_list)