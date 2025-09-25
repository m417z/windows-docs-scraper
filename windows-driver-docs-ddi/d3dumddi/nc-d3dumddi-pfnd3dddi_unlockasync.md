# PFND3DDDI_UNLOCKASYNC callback function

## Description

The *UnlockAsync* function unlocks a resource or a surface within the resource that the [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync) function previously locked.

## Parameters

### `hDevice`

A handle to a display device (that is, the graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_UNLOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_unlockasync) structure that describes the resource or surface within the resource to unlock.

## Return value

*UnlockAsync* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The resource is successfully unlocked. |
| **E_OUTOFMEMORY** | UnlockAsync could not allocate the required memory for it to complete. |
| **E_INVALIDARG** | The resource that [D3DDDIARG_UNLOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_unlockasync) describes was not locked by a previous call to the driver's [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync) function. |

## Remarks

A user-mode display driver should call the [pfnUnlockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockcb) function with the appropriate allocation handle after the *UnlockAsync* function is called.

A user-mode display driver optionally implements *UnlockAsync*; the Microsoft Direct3D runtime calls *UnlockAsync* only if the driver implements the [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync), *UnlockAsync*, and [Rename](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rename) functions.

Like [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync), *UnlockAsync* is called on the main application thread while most other calls to the user-mode display driver functions are made on a worker thread (on multiple-processor computers).

If a user-mode display driver exposes a DDI version of 0x0000000B or greater (the driver returns this value in the **DriverVersion** member of the [D3D10DDIARG_OPENADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_openadapter) structure in a call to the driver's [OpenAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openadapter) function), the Direct3D runtime will call *UnlockAsync* in a reentrant manner. When the runtime calls *UnlockAsync* in a reentrant manner, one thread can execute inside *UnlockAsync* while another thread that references the same display device executes inside of another user-mode display driver function.

## See also

[D3DDDIARG_UNLOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_unlockasync)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync)

[Rename](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rename)

[pfnUnlockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockcb)