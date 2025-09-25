# _WWAN_UICC_ACCESS_BINARY structure

## Description

The **WWAN_UICC_ACCESS_BINARY** structure describes information about a UICC binary file to read or to which to write.

## Members

### `Version`

The version number of the structure that follows. In Windows 10, version 1903, this version must be set to **1**.

### `AppId`

The application ID.

### `UiccFilePath`

A formatted [**WWAN_UICC_FILE_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_file_path) structure that describes the file path of the UICC binary file.

### `FileOffset`

The offset to use when reading from the file. This field can be bigger than 256, and it combines both offset high and offset low as defined in the [ETSI TS 102 221 technical specification](https://go.microsoft.com/fwlink/p/?linkid=864594).

### `NumberOfBytes`

The number of bytes to be read. For example, a client driver could use this function to read a transparent (binary) file that is larger than 256 bytes, although the maximum amount that can be read or written in a single UICC operation is 256 bytes per the [ETSI TS 102 221 technical specification](https://go.microsoft.com/fwlink/p/?linkid=864594). It is the function's responsibility to split this into multiple APDUs and send the result back in a single response.

### `LocalPinSize`

The size of the password, in bytes.

### `LocalPin`

The password for the UICC.

### `BinaryDataSize`

The size of the binary data, in bytes.

### `BinaryData`

Used only in Set (write) operations. Contains the data to write to the file.

## Remarks

This structure is used in the [**NDIS_WWAN_UICC_ACCESS_BINARY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_access_binary) structure.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_ACCESS_BINARY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-access-binary)

[**NDIS_WWAN_UICC_ACCESS_BINARY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_access_binary)