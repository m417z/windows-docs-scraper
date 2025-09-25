# _WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS structure

## Description

The WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS union describes which members of a [WHEA_PCIXBUS_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixbus_error_section) structure contain valid data.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.ErrorStatus`

A single bit that indicates that the **ErrorStatus** member of the WHEA_PCIXBUS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.ErrorType`

A single bit that indicates that the **ErrorType** member of the WHEA_PCIXBUS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.BusId`

A single bit that indicates that the **BusId** member of the WHEA_PCIXBUS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.BusAddress`

A single bit that indicates that the **BusAddress** member of the WHEA_PCIXBUS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.BusData`

A single bit that indicates that the **BusData** member of the WHEA_PCIXBUS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.BusCommand`

A single bit that indicates that the **BusCommand** member of the WHEA_PCIXBUS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.RequesterId`

A single bit that indicates that the **RequesterId** member of the WHEA_PCIXBUS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.CompleterId`

A single bit that indicates that the **CompleterId** member of the WHEA_PCIXBUS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.TargetId`

A single bit that indicates that the **TargetId** member of the WHEA_PCIXBUS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `ValidBits`

A ULONGLONG representation of the contents of the WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS union.

## Remarks

A WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS union is contained within the [WHEA_PCIXBUS_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixbus_error_section) structure.

## See also

[WHEA_PCIXBUS_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixbus_error_section)