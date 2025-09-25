# _WWAN_UICC_FILE_TYPE enumeration

## Description

The **WWAN_UICC_FILE_TYPE** enumeration specifies the type for a UICC file.

## Constants

### `WwanUiccFileTypeUnknown`

File type unknown.

### `WwanUiccFileTypeWorkingEf`

A working EF file.

### `WwanUiccFileTypeInternalEf`

An internal EF file.

### `WwanUiccFileTypeDfOrAdf`

A dedicated file, a directory that is the parent of other nodes. This might be a DF or ADF.

### `WwanUiccFileTypeMax`

The maximum value for this enumeration.

## Remarks

This enumeration is used in the [**WWAN_UICC_FILE_STATUS*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_file_status) structure.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_FILE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-file-status)

[**WWAN_UICC_FILE_STATUS*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_file_status)