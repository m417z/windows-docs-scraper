# ScsiDebugPrint function (minitape.h)

## Description

The **ScsiDebugPrint** routine prints debug information with a level of verbosity based on global values set in the kernel debugger or set in the registry and initialized when the system boots.

> [!NOTE]
> The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Use the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models instead.

## Parameters

### `DebugPrintLevel`

Contains a value between 0 and 3 that specifies the level of verbosity, where a value of 3 signifies the highest level of verbosity and a value of 0 signifies the lowest level. See Remarks.

### `DebugMessage`

Pointer to the debug string to print.

### `...`

Variadic arguments to be printed with the string that **DebugMessage** points to.

## Return value

None

## Remarks

**ScsiDebugPrint** prints the message pointed to by **DebugMessage**, along with other debugging information depending on the vaue of **DebugPrintLevel** as follows.

| DebugPrintLevel value | Value Passed to DbgPrintEx |
| --------------------- | -------------------------- |
| 0 | DPFLTR_WARNING_LEVEL |
| 1 | DPFLTR_TRACE_LEVEL |
| 2 | DPFLTR_TRACE_LEVEL |
| 3 | DPFLTR_INFO_LEVEL |

To view the message pointed to by **DebugMessage** from the kernel debugger, use the component filter mask Kd_ScsiMiniPort_Mask. For more information about debugging masks, see [**DbgPrintEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprintex).

**ScsiDebugPrint** only functions in checked builds; it compiles to nothing in free builds.

## See also

[**DbgPrintEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprintex)