# _GENERIC_MAPPING structure

## Description

The **GENERIC_MAPPING** structure describes the [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value of specific access rights associated with each type of generic access right.

## Members

### `GenericRead`

Describes the specific access rights corresponding to the GENERIC_READ access right.

### `GenericWrite`

Describes the specific access rights corresponding to the GENERIC_WRITE access right.

### `GenericExecute`

Describes the specific access rights corresponding to the GENERIC_EXECUTE access right.

### `GenericAll`

Describes the specific access rights corresponding to the GENERIC_ALL access right.

## Remarks

Use the [IoGetFileObjectGenericMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetfileobjectgenericmapping) routine to get the specific access rights corresponding to generic access rights for file objects. Use [RtlMapGenericMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlmapgenericmask) to subtract off the access rights within an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) that do not derive from generic access rights.

For more information about generic access rights, see the Win32 reference page for the [**GENERIC_MAPPING**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-generic_mapping) structure.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[IoGetFileObjectGenericMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetfileobjectgenericmapping)

[RtlMapGenericMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlmapgenericmask)