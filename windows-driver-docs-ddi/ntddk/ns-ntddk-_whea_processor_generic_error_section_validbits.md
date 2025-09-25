# _WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS structure

## Description

The WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS union describes which members of a [WHEA_PROCESSOR_GENERIC_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_generic_error_section) structure contain valid data.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.ProcessorType`

A single bit that indicates that the **ProcessorType** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.InstructionSet`

A single bit that indicates that the **InstructionSet** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.ErrorType`

A single bit that indicates that the **ErrorType** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Operation`

A single bit that indicates that the **Operation** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Flags`

A single bit that indicates that the **Flags** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Level`

A single bit that indicates that the **Level** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.CPUVersion`

A single bit that indicates that the **CPUVersion** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.CPUBrandString`

A single bit that indicates that the **CPUBrandString** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.ProcessorId`

A single bit that indicates that the **ProcessorId** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.TargetAddress`

A single bit that indicates that the **TargetAddress** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.RequesterId`

A single bit that indicates that the **RequesterId** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.ResponderId`

A single bit that indicates that the **ResponderId** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.InstructionPointer`

A single bit that indicates that the **InstructionPointer** member of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `ValidBits`

A ULONGLONG representation of the contents of the WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS union.

### `DUMMYSTRUCTNAME.NativeModelId`

## Remarks

A WHEA_PROCESSOR_GENERIC_ERROR_SECTION_VALIDBITS union is contained within the [WHEA_PROCESSOR_GENERIC_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_generic_error_section) structure.

## See also

[WHEA_PROCESSOR_GENERIC_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_generic_error_section)