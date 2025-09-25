# _WWAN_UICC_FILE_STRUCTURE enumeration

## Description

The **WWAN_UICC_FILE_STRUCTURE** enumeration specifies the structure of a UICC file.

## Constants

### `WwanUiccFileStructureUnknown`

An unknown file structure.

### `WwanUiccFileStructureTransparent`

A single record of variable length.

### `WwanUiccFileStructureCyclic`

A cyclic set of records, each of the same length.

### `WwanUiccFileStructureLinear`

A linear set of records, each of the same length.

### `WwanUiccFileStructureBerTLV`

A set of data values accessible by tag.

### `WwanUiccFileStructureMax`

The maximum value for this enumeration.

## Remarks

This enumeration is used in the [**WWAN_UICC_FILE_STATUS*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_file_status) structure.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_FILE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-file-status)

[**WWAN_UICC_FILE_STATUS*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_file_status)