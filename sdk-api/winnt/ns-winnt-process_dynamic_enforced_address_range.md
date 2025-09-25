## Description

> [!NOTE]
> This API was added to the 19041 SDK in an update released in November 2020.

Contains dynamic enforced address ranges used by various features related to user-mode Hardware-enforced Stack Protection (HSP). The [SetProcessDynamicEnforcedCetCompatibleRanges](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessdynamicenforcedcetcompatibleranges) function uses this structure.

## Members

### `BaseAddress`

The base address of a dynamic enforced address range.

### `Size`

The size in bytes of a dynamic enforced address range.

### `Flags`

Flags that apply to the dynamic enforced address range described by *BaseAddress* and *Size*.

| Value | Meaning |
| --- | --- |
| **DYNAMIC_ENFORCED_ADDRESS_RANGE_ADD**<br><br>0x00000001UL | Dynamic enforced address range should be added. If this flag is not set, the range is removed. This is an input flag. |
| **DYNAMIC_ENFORCED_ADDRESS_RANGE_PROCESSED**<br><br>0x00000002UL | Dynamic enforced address range has been successfully processed (either added or removed). This is an output flag used to report which ranges were successfully processed when processing an array of multiple ranges. |

## Remarks

## See also