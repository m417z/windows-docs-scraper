## Description

**StorPortTerminateSystemThread** terminates the current system thread.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport's hardware device extension.

### `ThreadContext` [in/optional]

Pointer to the thread context received in a prior call to [**StorPortCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcreatesystemthread).

## Remarks

A miniport-created system thread calls **StorPortTerminateSystemThread** to terminate itself. A miniport that creates its own threads must ensure that each such thread terminates. The miniport must not terminate any threads that the system or other drivers created.

## See also

[**StorPortCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcreatesystemthread)