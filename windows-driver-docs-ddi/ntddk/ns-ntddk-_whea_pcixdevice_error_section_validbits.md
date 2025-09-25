# _WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS structure

## Description

The WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS union describes which members of a [WHEA_PCIXDEVICE_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixdevice_error_section) structure contain valid data.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.ErrorStatus`

A single bit that indicates that the **ErrorStatus** member of the WHEA_PCIXDEVICE_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.IdInfo`

A single bit that indicates that the **IdInfo** member of the WHEA_PCIXDEVICE_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.MemoryNumber`

A single bit that indicates that the **MemoryNumber** member of the WHEA_PCIXDEVICE_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.IoNumber`

A single bit that indicates that the **IoNumber** member of the WHEA_PCIXDEVICE_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.RegisterDataPairs`

A single bit that indicates that the **RegisterDataPairs** member of the WHEA_PCIXDEVICE_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `ValidBits`

A ULONGLONG representation of the contents of the WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS union.

## Remarks

A WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS union is contained within the [WHEA_PCIXDEVICE_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixdevice_error_section) structure.

## See also

[WHEA_PCIXDEVICE_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixdevice_error_section)