# _WWAN_UICC_ACCESS_RECORD structure

## Description

The **WWAN_UICC_ACCESS_RECORD** structure describes information about a UICC linear fixed or cyclic file to read or to which to write.

## Members

### `Version`

The version number of the structure that follows. In Windows 10, version 1903, this version must be set to **1**.

### `AppId`

The application ID.

### `UiccFilePath`

A formatted [**WWAN_UICC_FILE_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_file_path) structure that describes the file path of the UICC linear fixed or cyclic file.

### `RecordNumber`

The record number. This represents the absolute record index at all times. Relative record access is not supported because the modem can perform multiple accesses on a file (NEXT, PREVIOUS).

### `LocalPinSize`

The size of the password, in bytes.

### `LocalPin`

The password for the UICC.

### `RecordDataSize`

The size of the record data, in bytes.

### `RecordData`

Used only in Set (write) operations. Contains the data to write to the file.

## Remarks

This structure is used in the [**NDIS_WWAN_UICC_ACCESS_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_access_record) structure.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_ACCESS_RECORD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-access-record)

[**NDIS_WWAN_UICC_ACCESS_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_access_record)