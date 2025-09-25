## Description

The WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS union describes which members of a [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structure contain valid data.

## Members

### `DUMMYSTRUCTNAME`

Defines the **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.FRUId`

A single bit that indicates that the **FRUId** member of the WHEA_ERROR_RECORD_SECTION_DESCRIPTOR structure contains valid data.

### `DUMMYSTRUCTNAME.FRUText`

A single bit that indicates that the **FRUText** member of the WHEA_ERROR_RECORD_SECTION_DESCRIPTOR structure contains valid data.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `AsUCHAR`

A UCHAR representation of the contents of the **WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS** union.

## Remarks

A WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS union is contained within the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structure.

## See also

[**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)