# IDebugClient3::AttachKernel

## Description

The **AttachKernel** methods connect the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/d) to a kernel target.

## Parameters

### `Flags` [in]

Specifies the flags that control how the debugger attaches to the kernel target. The possible values are:

| Value | Description |
| --- | --- |
| DEBUG_ATTACH_KERNEL_CONNECTION | Attach to the kernel on the target computer. |
| DEBUG_ATTACH_EXDI_DRIVER | Attach to a kernel by using an eXDI driver. |

### `ConnectOptions` [in, optional]

Specifies the connection settings for communicating with the computer running the kernel target. The interpretation of *ConnectOptions* depends on the value of *Flags*.

#### DEBUG_ATTACH_KERNEL_CONNECTION

*ConnectOptions* will be interpreted the same way as the options that follow the **-k** switch on the WinDbg and KD command lines. Environment variables affect *ConnectOptions* in the same way they affect the **-k** switch.

#### DEBUG_ATTACH_EXDI_DRIVER

eXDI drivers are not described in this documentation. If you have an eXDI interface to your hardware probe or hardware simulator, please contact Microsoft for debugging information.

##### - ConnectOptions.DEBUG_ATTACH_EXDI_DRIVER

eXDI drivers are not described in this documentation. If you have an eXDI interface to your hardware probe or hardware simulator, please contact Microsoft for debugging information.

##### - ConnectOptions.DEBUG_ATTACH_KERNEL_CONNECTION

*ConnectOptions* will be interpreted the same way as the options that follow the **-k** switch on the WinDbg and KD command lines. Environment variables affect *ConnectOptions* in the same way they affect the **-k** switch.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

**Note** The engine doesn't completely attach to the kernel until the [WaitForEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-waitforevent) method has been called. Only after the kernel has generated an event -- for example, the initial breakpoint -- does it become available in the debugger session.

For more information about connecting to live kernel-mode targets, see [Live Kernel-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-kernel-mode-targets).

## See also

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[GetKernelConnectionOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getkernelconnectionoptions)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[IsKernelDebuggerEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-iskerneldebuggerenabled)