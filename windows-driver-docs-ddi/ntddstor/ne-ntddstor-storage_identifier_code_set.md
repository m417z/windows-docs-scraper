## Description

The STORAGE\_IDENTIFIER\_CODE\_SET enumeration specifies the code set used by a SCSI identification descriptor ([**STORAGE\_IDENTIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_identifier)) to identify a logical unit.

## Constants

### `StorageIdCodeSetReserved`

Reserved.

### `StorageIdCodeSetBinary`

Indicates that the identification descriptor contains a binary representation of the identifier.

### `StorageIdCodeSetAscii`

Indicates that the identification descriptor contains an ASCII representation of the identifier.

### `StorageIdCodeSetUtf8`

Indicates that the identification descriptor contains a UTF8 representation of the identifier.

## Remarks

This field is intended to be an aid to software that displays the identifier field. Every device identification page (page code 0x83) of SCSI vital product data contains a series of identification descriptors, each of which contains an identifier.

## See also

[**STORAGE\_IDENTIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_identifier)