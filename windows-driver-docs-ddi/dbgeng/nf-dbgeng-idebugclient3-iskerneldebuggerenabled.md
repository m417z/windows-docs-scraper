# IDebugClient3::IsKernelDebuggerEnabled

## Description

The **IsKernelDebuggerEnabled** method checks whether kernel debugging is enabled for the local kernel.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | Kernel debugging is enabled for the local kernel. |
| **S_FALSE** | Kernel debugging is not enabled for the local kernel. |

## Remarks

Kernel debugging is available for the local computer if the computer was booted by using the **/debug** boot switch. In some Windows installations, [local kernel debugging](https://learn.microsoft.com/windows-hardware/drivers/debugger/security-during-kernel-mode-debugging) is supported when other switches--such as **/debugport**--are used, but this is not a guaranteed feature of Windows and should not be relied on. For more information about kernel debugging on a single computer, see [Performing Local Kernel Debugging](https://learn.microsoft.com/windows-hardware/drivers/debugger/performing-local-kernel-debugging).

For more information about connecting to live kernel-mode targets, see [Live Kernel-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-kernel-mode-targets).

## See also

[AttachKernel](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachkernel)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)