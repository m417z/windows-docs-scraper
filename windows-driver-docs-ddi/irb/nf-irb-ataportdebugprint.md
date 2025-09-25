# AtaPortDebugPrint function

## Description

The **AtaPortDebugPrint** routine passes a message string to the kernel debugger for the debugger to print.

> [!NOTE]
>
> The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Use the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models instead.

## Parameters

### `DebugPrintLevel`

Contains a value between 0 and 3 that specifies the level of verbosity, where a value of 3 signifies the highest level of verbosity and a value of 0 signifies the lowest level. See Remarks.

### `DebugMessage`

Pointer to the debug string to print.

### `...`

Variadic arguments to be used with the string that **DebugMessage** points to.

## Remarks

**ScsiDebugPrint** will print the message pointed to by **DebugMessage**, along with other debugging information depending on the value of **DebugPrintLevel** and a port driver-specific mask. Use the **nt!kd_idep_mask** command to set the desired level of verbosity. For more information about the kernel debugger, see [Getting Started with WinDbg - Kernel Mode](https://learn.microsoft.com/windows-hardware/drivers/debugger/getting-started-with-windbg--kernel-mode-).

## See also

[**DbgPrintEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprintex)