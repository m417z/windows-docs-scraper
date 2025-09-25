# _WHEA_MEMORY_ERROR_SECTION structure

## Description

The WHEA_MEMORY_ERROR_SECTION structure describes platform memory error data.

## Members

### `ValidBits`

A [WHEA_MEMORY_ERROR_SECTION_VALIDBITS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_memory_error_section_validbits) union that specifies which members of this structure contain valid data.

### `ErrorStatus`

A [WHEA_ERROR_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_status) structure that contains memory error status data.

This member contains valid data only if the **Validbits.ErrorStatus** bit is set.

### `PhysicalAddress`

The physical address where the memory error occurred.

This member contains valid data only if the **Validbits.PhysicalAddress** bit is set.

### `PhysicalAddressMask`

A bit mask that specifies which of the bits in the **PhysicalAddress** member contain valid address data.

This member contains valid data only if the **Validbits.PhysicalAddressMask** bit is set.

### `Node`

The identifier of the node that contains the memory where the memory error occurred in a system with multiple nodes.

This member contains valid data only if the **Validbits.Node** bit is set.

### `Card`

The card number of the card that contains the memory where the memory error occurred.

This member contains valid data only if the **Validbits.Card** bit is set.

### `Module`

The module number of the module that contains the memory where the memory error occurred.

This member contains valid data only if the **Validbits.Module** bit is set.

### `Bank`

The bank number of the memory bank that contains the memory where the memory error occurred.

This member contains valid data only if the **Validbits.Bank** bit is set.

### `Device`

The device number of the memory device that contains the memory where the memory error occurred.

This member contains valid data only if the **Validbits.Device** bit is set.

### `Row`

The row number of the location where the memory error occurred.

This member contains valid data only if the **Validbits.Row** bit is set.

### `Column`

The column number of the location where the memory error occurred.

This member contains valid data only if the **Validbits.Column** bit is set.

### `BitPosition`

The bit position where the memory error occurred.

This member contains valid data only if the **Validbits.BitPosition** bit is set.

### `RequesterId`

An identifier that uniquely identifies the requester associated with the error.

This member contains valid data only if the **Validbits.RequesterId** bit is set.

### `ResponderId`

An identifier that uniquely identifies the responder associated with the error.

This member contains valid data only if the **Validbits.ResponderId** bit is set.

### `TargetId`

The hardware address of the intended target of the transaction.

This member contains valid data only if the **Validbits.TargetId** bit is set.

### `ErrorType`

The type of memory error that occurred. Possible values are:

| Possible Values |Description |
| --------------------------------- | ----------------------------------- |
| WHEA_MEMERRTYPE_UNKNOWN | An unknown error. |
| WHEA_MEMERRTYPE_NOERROR | No error occurred.|
| WHEA_MEMERRTYPE_SINGLEBITECC | A single bit [ECC](https://learn.microsoft.com/windows-hardware/drivers/) error. |
| WHEA_MEMERRTYPE_MULTIBITECC | multibit ECC error. |
| WHEA_MEMERRTYPE_SINGLESYMCHIPKILL | A single symbol ChipKill ECC error. |
| WHEA_MEMERRTYPE_MULTISYMCHIPKILL | A multiple symbol ChipKill ECC error. |
| WHEA_MEMERRTYPE_MASTERABORT | A master abort. |
| WHEA_MEMERRTYPE_TARGETABORT | A target abort. |
| WHEA_MEMERRTYPE_PARITYERROR | A parity error. |
| WHEA_MEMERRTYPE_WATCHDOGTIMEOUT | A watchdog timeout. |
| WHEA_MEMERRTYPE_INVALIDADDRESS | An invalid memory address. |
| WHEA_MEMERRTYPE_MIRRORBROKEN | A broken memory mirror. |
| WHEA_MEMERRTYPE_MEMORYSPARING | A memory sparing error. |

This member contains valid data only if the **Validbits.ErrorType** bit is set.

### `Extended`

Contains valid data only if the **ValidBits.ExtendedRow** bits is set.

If **ValidBits.Row** is not set, the **Row** member contains row number bits (15:0) and Extended contains row number bits (17:16). Bit 0 is the 16th bit of the **Row**. Bit 1 is the 17th bit of the **Row**.

If **ValidBits.ChipIdentification** is set, Bits 7:5 contain Chip Identification.

This value is available starting Windows 10, version 1803.

### `RankNumber`

The Rank number of the memory error location. This member contains valid data only if the **ValidBits.RankNumber** bit is set. This value is available starting Windows 10, version 1803.

### `CardHandle`

Contains the SMBIOS handle for the Memory Array Structure that represents the Memory Card. This member contains valid data only if the **ValidBits.CardHandle** is set. This value is available starting Windows 10, version 1803.

### `ModuleHandle`

Contains the SMBIOS handle for the Memory Device Structure that represents the Memory Module. This member contains valid data only if the **ValidBits.ModuleHandle** is set. This value is available starting Windows 10, version 1803.

## Remarks

The WHEA_MEMORY_ERROR_SECTION structure describes the error data that is contained in a platform memory error section of an [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). An error record contains a platform memory error section only if the **SectionType** member of one of the [WHEA_ERROR_RECORD_SECTION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structures that describe the error record sections for that error record contains MEMORY_ERROR_SECTION_GUID.

## See also

[WHEA_ERROR_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85))

[WHEA_ERROR_RECORD_SECTION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)

[WHEA_ERROR_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_status)

[WHEA_MEMORY_ERROR_SECTION_VALIDBITS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_memory_error_section_validbits)