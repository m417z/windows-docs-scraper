# IDebugClient4::GetKernelConnectionOptions

## Description

The **GetKernelConnectionOptions** method returns the connection options for the current kernel target.

## Parameters

### `Buffer` [out, optional]

Specifies the buffer to receive the connection options.

### `BufferSize` [in]

Specifies the size in characters of the buffer *Buffer*. This size includes the space for the '\0' terminating character.

### `OptionsSize` [out, optional]

Receives the size in characters of the connection options. This size includes the space for the '\0' terminating character. If *OptionsSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The size of the string was greater than the size of the buffer, so it was truncated to fit into the buffer. |
| **E_UNEXPECTED** | The current target is not a standard live kernel target. |

## Remarks

This method is available only for live kernel targets that are not local and not connected through eXDI.

The connection options returned are the same options used to connect to the kernel.

For more information about connecting to live kernel-mode targets, see [Live Kernel-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-kernel-mode-targets).

## See also

[AttachKernel](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachkernel)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)