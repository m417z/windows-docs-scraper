## Description

A kernel-mode graphics driver (KMD) calls **DxgkcbInvalidatehwcontext** to invalidate a hardware context.

## Parameters

### `unnamedParam1` [in]

Pointer to a [**DXGKARGCB_INVALIDATEHWCONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_invalidatehwcontext) structure that contains information for *Dxgkrnl* to use to invalidate the hardware context.

## Return value

**DxgkcbInvalidatehwcontext** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

KMD calls **DxgkcbInvalidatehwcontext** to notify the system when the state and resources associated with a hardware context are no longer valid or consistent, thus requiring that the context be reset or reinitialized before it can be used again. A context needs to be invalidated in the event of a hardware engine reset operation that can be due to a variety of reasons, such as recovery from a fault or reconfiguration of the GPU resources.

*Dxgkrnl* marks the context as invalid so that it's no longer scheduled for execution on the GPU. It then initiates any necessary cleanup such as releasing resources associated with the context or resetting any state associated with the context.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_INVALIDATEHWCONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_invalidatehwcontext) and then call **DxgkCbInvalidateHwContext** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_INVALIDATEHWCONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_invalidatehwcontext)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)