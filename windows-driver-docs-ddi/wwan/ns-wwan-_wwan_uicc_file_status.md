# _WWAN_UICC_FILE_STATUS structure

## Description

The **WWAN_UICC_FILE_STATUS** structure describes the status of a UICC file.

## Members

### `Version`

The version number of the structure that follows. In Windows 10, version 1903, this version must be set to **1**.

### `StatusWord1`

A return parameter specific to the UICC command.

### `StatusWord2`

A return parameter specific to the UICC command.

### `FileAccessibility`

A [**WWAN_UICC_FILE_ACCESSIBILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_uicc_file_accessibility) value that specifies the UICC file accessibility.

### `FileType`

A [**WWAN_UICC_FILE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_uicc_file_type) value that specifies the UICC file type.

### `FileStructure`

A [**WWAN_UICC_FILE_STRUCTURE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_uicc_file_structure) value that specifies the UICC file structure.

### `ItemCount`

The number of items in the UICC file. For transparent and TLV files, this is set to **1**.

### `ItemSize`

The size of each item, in bytes. For transparent or TLV files, this is the size of the entire EF. For record-based files, this represents the total number of records.

### `FileLockStatus`

A [**WWAN_PIN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pin_type) value that specifies the access condition for each operation (READ, UPDATE, ACTIVATE, and DEACTIVATE in that order) on the file.

## Remarks

This structure is used in the [**NDIS_WWAN_UICC_FILE_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_file_status) structure.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_FILE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-file-status)

[**NDIS_WWAN_UICC_FILE_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_file_status)