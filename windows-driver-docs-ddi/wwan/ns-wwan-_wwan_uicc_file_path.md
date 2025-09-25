# _WWAN_UICC_FILE_PATH structure

## Description

The **WWAN_UICC_FILE_PATH** structure describes file path information about a UICC file.

## Members

### `Version`

The version number of the structure that follows. In Windows 10, version 1903, this version must be set to **1**.

### `AppIdLength`

The size of the application ID, in bytes, as defined in Section 8.3 of the [ETSI TS 102 221 technical specification](https://go.microsoft.com/fwlink/p/?linkid=864594). For 2G cards, this field must be set to zero (0).

### `AppId`

The application ID. Only the first **AppIdLength** bytes are meaningful. If the application ID is longer than **WWAN_UICC_APP_ID_MAX_LEN** bytes, then **AppIdLength** specifies the actual length but only the first **WWAN_UICC_APP_ID_MAX_LEN** bytes are in this field.

### `FilePathLength`

The size of the file path, in bytes.

### `FilePath`

The file path, which is an array of 16-bit file IDs. The first ID must be either **0x7FFF** or **0x3F00**. If the first ID is **0x7FFF**, then the path is relative to the ADF of the application designated by **AppId**. Otherwise, it is an absolute path starting from the MF.

## Remarks

This structure is used in the [**NDIS_WWAN_UICC_FILE_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_file_path) structure.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_FILE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-file-status)

[**NDIS_WWAN_UICC_FILE_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_file_path)