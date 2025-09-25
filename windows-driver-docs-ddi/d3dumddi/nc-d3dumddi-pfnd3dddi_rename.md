# PFND3DDDI_RENAME callback function

## Description

The *Rename* function informs a user-mode display driver to start using the renamed allocation that the [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync) function previously returned for the specified resource.

## Parameters

### `hDevice`

A handle to a display device (that is, the graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_RENAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_rename) structure that describes the resource or surface within a resource to rename with a new allocation.

## Return value

*Rename* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The resource is successfully renamed.|
|E_OUTOFMEMORY|Rename could not allocate the required memory for it to complete.|

## Remarks

On multiple-processor computers, the Microsoft Direct3D runtime calls the user-mode display driver's *Rename* function from a worker thread instead of from the main application thread. The runtime calls *Rename*, at most, once for each successful call to the driver's [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync) function with the **Discard** bit-field flag set in the **Flags** member of the [D3DDDIARG_LOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lockasync) structure that the *pData* parameter of *LockAsync* points to.

*Rename* informs the driver to start using the renamed allocation that is specified by the **hCookie** member of the [D3DDDIARG_RENAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_rename) structure that the *pData* parameter of *Rename* points to. The **hCookie** handle was previously returned by the [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync) function if the **Discard** bit-field flag was set for the locked resource.

After *Rename* returns successfully (with S_OK), the user-mode display driver should use the allocation that **hCookie** specifies for all rendering operations that reference the resource that the **hResource** and **SubResourceIndex** members of D3DDDIARG_RENAME specify.

## See also

[D3DDDIARG_LOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lockasync)

[D3DDDIARG_RENAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_rename)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync)

[Rename](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rename)