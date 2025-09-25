# PFND3DDDI_LOCKASYNC callback function

## Description

The *LockAsync* function locks the specified resource or a surface within the resource.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_LOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lockasync) structure that describes the resource or surface within the resource to lock.

## Return value

*LockAsync* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The resource is successfully locked. |
| **E_OUTOFMEMORY** | LockAsync could not allocate the required memory for it to complete. |
| **D3DDDIERR_WASSTILLDRAWING** | Renaming the allocation that corresponds to the resource that the [D3DDDIARG_LOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lockasync) structure specifies failed.<br>The driver returns this value only if the Discard bit-field flag was set in the Flags member of D3DDDIARG_LOCKASYNC. |
| **E_NOTIMPL** | The user-mode display driver does not support LockAsync for the specified resource. |

## Remarks

On multiple-processor computers, the Microsoft Direct3D runtime might call most functions of the user-mode display driver from a worker thread instead of from the main application thread. This multiple-processor optimization is transparent to the user-mode display driver. When the runtime uses multiple-processor optimization, it might call *LockAsync* rather than the [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) function to lock a resource.

A user-mode display driver optionally implements *LockAsync*; the Direct3D runtime calls *LockAsync* only if the driver implements the *LockAsync*, [UnlockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockasync), and [Rename](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rename) functions. However, a user-mode display driver should implement *LockAsync* and the *UnlockAsync* and *Rename* functions because applications that frequently lock dynamic resources can then achieve higher performance.

When the Direct3D runtime uses multiple-processor optimization, it calls most user-mode display driver functions from a worker thread that the runtime manages; however, the runtime calls *LockAsync* on the application's main thread.

If a user-mode display driver exposes a DDI version of 0x0000000B or greater (the driver returns this value in the DriverVersion member of the [D3D10DDIARG_OPENADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_openadapter) structure in a call to the driver's [OpenAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openadapter) function), the Direct3D runtime will call LockAsync in a reentrant manner. When the runtime calls LockAsync in a reentrant manner, one thread can execute inside LockAsync while another thread that references the same display device executes inside of another user-mode display driver function. Additionally, on this type of driver, the runtime will call LockAsync for system memory surfaces. If the **Discard** bit-field flag is set in the **Flags** member of [D3DDDIARG_LOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lockasync), the driver should attempt to rename the allocation that corresponds to the resource. Typically, to rename an allocation, the driver calls the [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function with the allocation handle that corresponds to the resource to be locked.

The driver should set the **Discard** bit-field flag in the **Flags** member of the [D3DDDICB_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock) structure when the driver calls **pfnLockCb**. The driver should set the **NoExistingReference** bit-field flag of D3DDDICB_LOCK when the driver calls **pfnLockCb** only if the **NoExistingReferences** bit-field flag is set to **TRUE** in the **Flags** member of D3DDDIARG_LOCKASYNC, and the driver has no internally queued references to the resource.

If the driver fails to rename the allocation, the driver's *LockAsync* function should return the failure back to the runtime, and the driver should not flush its command buffer. If the renaming succeeds, the driver should return pointers to resource memory, pitch, and slice pitch and a handle to the resource that represents the renamed allocation in the members of [D3DDDIARG_LOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lockasync). The driver should not update its internal tracking structures with the new allocation handle that **pfnLockCb** returns. Instead, the driver should wait until its [Rename](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rename) function is called.

If the **NoOverwrite** bit-field flag is set in the **Flags** member of D3DDDIARG_LOCKASYNC, the driver should lock the corresponding allocation with no-overwrite semantics. The driver should call [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) with the **IgnoreSync** bit-field flag set in the **Flags** member of [D3DDDICB_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock) and should then return pointers to resource memory, pitch, and slice pitch to the Direct3D runtime in the members of [D3DDDIARG_LOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lockasync). If the driver returns success (S_OK) from a call to its *LockAsync* with the **NoOverwrite** bit-field flag set, it might be called to render with a locked surface. The driver should return success from a call to its *LockAsync* with **NoOverwrite** set only for surfaces that can be rendered while locked. The video memory manager requires that the allocations that correspond to the surfaces must be supported in AGP or aperture segments; otherwise, calls to the **pfnRenderCb** function fail when the command buffer references a locked allocation.

In summary, the driver should fail calls to its *LockAsync* function if renaming fails or if no-overwrite semantics are not supported for the resource. However, the Direct3D runtime will recover from these failures. For all other situations, drivers should return success from *LockAsync* to improve performance on multiple-processor computers.

## See also

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource)

[D3DDDIARG_LOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lockasync)

[D3DDDICB_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock)

[Rename](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rename)

[UnlockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockasync)

[pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)