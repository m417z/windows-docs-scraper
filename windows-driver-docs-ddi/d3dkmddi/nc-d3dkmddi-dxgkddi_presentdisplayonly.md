# DXGKDDI_PRESENTDISPLAYONLY callback function

## Description

Presents the screen image to the display device of a kernel mode display-only driver (KMDOD).

## Parameters

### `hAdapter`

A handle to the device context for the display adapter. The KMDOD's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously returned this handle in the *MiniportDeviceContext* parameter.

### `pPresentDisplayOnly`

A pointer to a [DXGKARG_PRESENT_DISPLAYONLY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present_displayonly) structure that contains information about the present operation.

## Return value

Returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** |The present operation completed successfully. |
| **STATUS_PENDING** | The present operation has been sent to the software or hardware queue to complete. <br>In this case, the KMDOD should use an interrupt and deferred procedure call (DPC) to report progress of the current present operation. Otherwise the operating system uses the [Timeout Detection and Recovery (TDR)](https://learn.microsoft.com/windows-hardware/drivers/display/timeout-detection-and-recovery) process, which reports an error and requires the KMDOD to reinitialize itself and to reset the GPU.<br>Note that this status code should not be returned for synchronous mode, as described in Remarks. |

The driver can also return any other error status code defined in Ntstatus.h to indicate issues that have occurred with the present operation.

## Remarks

The KMDOD must complete all screen-to-screen moves before copying dirty rectangles. In addition, the KMDOD must complete each move/copy operation before beginning another move/copy operation.

The operating system supports two modes of KMDOD present operations: synchronous and asynchronous. Depending on hardware and driver implementation, the KMDOD can use either mode or switch between them at any time.

The operating system guarantees that this function follows the zero level synchronization mode as defined in [Threading and Synchronization Zero Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level).

## See also

[DXGKARGCB_NOTIFY_INTERRUPT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data)

[DXGKARG_PRESENT_DISPLAYONLY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present_displayonly)

[DxgkCbNotifyDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_dpc)

[DxgkCbNotifyInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[DxgkCbPresentDisplayOnlyProgress](https://learn.microsoft.com/windows-hardware/drivers/display/dxgkcbpresentdisplayonlyprogress)

[DxgkCbQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_queue_dpc)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)