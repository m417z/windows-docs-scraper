# IDebugClient5::SetKernelConnectionOptionsWide

## Description

The **SetKernelConnectionOptionsWide** method updates some of the connection options for a live kernel target.

## Parameters

### `Options` [in]

Specifies the connection options to update. The possible values are:

| Value | Description |
| --- | --- |
| "resync" | Re-synchronize the connection between the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) and the kernel. For more information, see [Synchronizing with the Target Computer](https://learn.microsoft.com/windows-hardware/drivers/debugger/synchronizing-with-the-target-computer). |
| "cycle_speed" | For kernel connections through a COM port, cycle through the supported baud rates; for other connections, do nothing. For more information, see [CTRL+A (Toggle Baud Rate)](https://learn.microsoft.com/windows-hardware/drivers/debugger/ctrl-a--toggle-baud-rate-). |

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_UNEXPECTED** | The current target is not a live (non-local) kernel target. |

## Remarks

This method is available only for live kernel targets that are not local and not connected through eXDI. This method is reentrant.

For more information about connecting to live kernel-mode targets, see [Live Kernel-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-kernel-mode-targets).

## See also

[AttachKernel](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachkernel)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)