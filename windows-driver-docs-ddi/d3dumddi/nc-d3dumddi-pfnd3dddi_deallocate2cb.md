# PFND3DDDI_DEALLOCATE2CB callback function

## Description

The **pfnDeallocate2Cb** user mode callback function releases allocations for a kernel-mode resource object if the resource object was created.

**pfnDeallocate2Cb** is a replacement for [pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb) that has an additional **Flags** member. When **Flags** are set to all zeroes, behavior is equivalent to *pfnDeallocateCb*.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_DEALLOCATE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_deallocate2) structure that describes the resource to release.

## Return value

|Return code|Description|
|--- |--- |
|S_OK|The memory was successfully released.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

When an allocation destruction request is received, VidMm assumes, by default, that commands queued prior to the destruction request may access the allocation being destroyed and defers the destruction operation until the queued commands finish. If the user mode driver (UMD) knows that pending commands don’t access the allocation being destroyed, it can instruct VidMm not to wait until pending commands are finished by setting the **AssumeNotInUse** flag to **TRUE** when calling **pfnDeallocate2Cb**.

If an application or UMD would like to ensure allocation memory is reclaimed prior to the return from the **pfnDeallocate2Cb** call (for example, to minimize peak memory usage if the surface is being re-created), it should set the **SynchronousDestroy** flag.

## See also

[D3DDDICB_DEALLOCATE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_deallocate2)

[pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb)