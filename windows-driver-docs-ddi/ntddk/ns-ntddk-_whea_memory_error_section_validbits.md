# _WHEA_MEMORY_ERROR_SECTION_VALIDBITS structure

## Description

The WHEA_MEMORY_ERROR_SECTION_VALIDBITS union describes which members of a [WHEA_MEMORY_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_memory_error_section) structure contain valid data.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.ErrorStatus`

A single bit that indicates that the **ErrorStatus** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Bank`

A single bit that indicates that the **PhysicalAddress** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.BitPosition`

A single bit that indicates that the **PhysicalAddressMask** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Card`

A single bit that indicates that the **Node** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Column`

A single bit that indicates that the **Card** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Device`

A single bit that indicates that the **Module** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.ErrorType`

A single bit that indicates that the **Device** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Module`

A single bit that indicates that the **Row** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Node`

A single bit that indicates that the **Column** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.PhysicalAddress`

A single bit that indicates that the **BitPosition** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.PhysicalAddressMask`

A single bit that indicates that the **RequesterId** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.RequesterId`

A single bit that indicates that the **ResponderId** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Reserved`

A single bit that indicates that the **TargetId** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.ResponderId`

A single bit that indicates that the **ErrorType** member of the WHEA_MEMORY_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Row`

Reserved for system use.

### `DUMMYSTRUCTNAME.TargetId`

A ULONGLONG representation of the contents of the WHEA_MEMORY_ERROR_SECTION_VALIDBITS union.

### `DUMMYSTRUCTNAME.RankNumber`

The Rank number of the memory error location. This member contains valid data only if the **ValidBits.RankNumber** bit is set. This value is available starting Windows 10, version 1803.

### `DUMMYSTRUCTNAME.CardHandle`

Contains the SMBIOS handle for the Memory Array Structure that represents the Memory Card. This member contains valid data only if the **ValidBits.CardHandle** is set. This value is available starting Windows 10, version 1803.

### `DUMMYSTRUCTNAME.ModuleHandle`

Contains the SMBIOS handle for the Memory Device Structure that represents the Memory Module. This member contains valid data only if the **ValidBits.ModuleHandle** is set. This value is available starting Windows 10, version 1803.

### `DUMMYSTRUCTNAME.ExtendedRow`

Contains valid data only if the **ValidBits.ExtendedRow** bits is set.

### `DUMMYSTRUCTNAME.BankGroup`

The bank number of the memory bank that contains the memory where the memory error occurred. If **Validbits.Bank** is set.

If **ValidBits.BankGroup** is set, the **Bank** member Bit (15:8) is Bank Group.

### `DUMMYSTRUCTNAME.BankAddress`

The bank number of the memory bank that contains the memory where the memory error occurred. If **Validbits.Bank** is set.

If **ValidBits.BankAddress** is set, the **Bank** member Bit (7:0) Bank Address.

### `DUMMYSTRUCTNAME.ChipIdentification`

If **ValidBits.ChipIdentification** is set, Bits 7:5 contain Chip Identification.

This value is available starting Windows 10, version 1803.

### `ValidBits`

## Remarks

A WHEA_MEMORY_ERROR_SECTION_VALIDBITS union is contained within the [WHEA_MEMORY_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_memory_error_section) structure.

## See also

[WHEA_MEMORY_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_memory_error_section)