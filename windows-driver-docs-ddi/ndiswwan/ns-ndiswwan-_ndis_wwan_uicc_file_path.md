# _NDIS_WWAN_UICC_FILE_PATH structure

## Description

The **NDIS_WWAN_UICC_FILE_PATH** structure describes file path information about a UICC file.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_UICC_FILE_PATH** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_UICC_FILE_PATH_REVISION_1 |
| Size | sizeof(NDIS_WWAN_UICC_FILE_PATH) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `UiccFilePath`

A formatted [**WWAN_UICC_FILE_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_file_path) structure that describes the file path for the UICC file.

## Remarks

This structure is used in the payload of an [OID_WWAN_UICC_FILE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-file-status) Query request.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_FILE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-file-status)

[NDIS_STATUS_WWAN_UICC_FILE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-uicc-file-status)

[**WWAN_UICC_FILE_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_file_path)