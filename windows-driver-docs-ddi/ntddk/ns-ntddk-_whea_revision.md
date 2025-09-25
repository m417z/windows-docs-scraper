# _WHEA_REVISION structure

## Description

The WHEA_REVISION union describes the revision of the error record data structures.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.MinorRevision`

The minor revision number.

### `DUMMYSTRUCTNAME.MajorRevision`

The major revision number.

### `AsUSHORT`

A USHORT representation of the contents of the WHEA_REVISION union.

## Remarks

A WHEA_REVISION union is contained within the [WHEA_ERROR_RECORD_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header) and the [WHEA_ERROR_RECORD_SECTION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structures.

## See also

[WHEA_ERROR_RECORD_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header)

[WHEA_ERROR_RECORD_SECTION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)