# DXGKCB_SIGNALEVENT callback function

## Description

A kernel-mode display driver (KMD) calls **DxgkCbSignalEvent** to signal an event.

## Parameters

### `unnamedParam1`

[in] Pointer to a [**DXGKARGCB_SIGNALEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_signalevent) structure that contains arguments for this call.

## Return value

**DxgkCbSignalEvent** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The driver must call **DxgkCbSignalEvent** with the **LastUse** flag during process or device cleanup.

During paravirtualization, KMD on the host can call **DxgkCbSignalEvent** to signal an event created on the guest. **DxgkCbSignalEvent** can also be used to signal events of the host processes as well.

In the case of [paravirtualization](https://learn.microsoft.com/windows-hardware/drivers/display/gpu-paravirtualization), **DxgkCbSignalEvent** doesn't signal the event synchronously, so the event isn't signaled when the callback returns. Otherwise, the event is signaled synchronously.

The IRQL for **DxgkCbSignalEvent** is:

* <= DISPATCH_LEVEL when signaling events of a process in a virtual machine.
* < DISPATCH_LEVEL when signaling events of a local process.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_SIGNALEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_signalevent) and then call **DxgkCbSignalEvent** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_SIGNALEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_signalevent)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)