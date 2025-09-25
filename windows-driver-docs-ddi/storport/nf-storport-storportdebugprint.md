# StorPortDebugPrint function

## Description

The **StorPortDebugPrint** routine prints a debug string to the kernel debugger, if the debugger is attached.

## Parameters

### `DebugPrintLevel`

Contains a value between 0 and 3 that specifies the level of verbosity, where a value of 3 signifies the highest level of verbosity and a value of 0 signifies the lowest level. See Remarks.

### `DebugMessage`

Pointer to the debug message to be printed.

### `...`

Variadic arguments to be printed with the string that **DebugMessage** points to.

## Return value

None

## Remarks

**StorPortDebugPrint** prints the message pointed to by **DebugMessage**, along with other debugging information depending on the value of **DebugPrintLevel** as follows.

| Value of DebugPrintLevel | Type of information printed |
| ------------------------ | --------------------------- |
| 0 | Error |
| 1 | Warning |
| 2 | Trace |
| 3 | Informational |

To see these debug strings, the driver writer must set nt!Kd_STORMINIPORT_Mask. This follows the new system-wide debug print mechanism.

## See also

[**DbgPrintEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprintex)