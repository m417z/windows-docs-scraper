# _NDIS_WWAN_UICC_ACCESS_RECORD structure

## Description

The **NDIS_WWAN_UICC_ACCESS_RECORD** structure describes information about a UICC linear fixed or cyclic file to read or to which to write.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_UICC_ACCESS_RECORD** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_UICC_ACCESS_RECORD_REVISION_1 |
| Size | sizeof(NDIS_WWAN_UICC_ACCESS_RECORD) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `UiccAccessRecord`

A formatted [**WWAN_UICC_ACCESS_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_access_record) structure that describes the linear fixed or cyclic UICC file.

## Remarks

This structure is used in the payload of an [OID_WWAN_UICC_ACCESS_RECORD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-access-record) Query or Set request.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_ACCESS_RECORD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-access-record)

[NDIS_STATUS_WWAN_UICC_RECORD_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-uicc-record-response)

[**WWAN_UICC_ACCESS_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_access_record)