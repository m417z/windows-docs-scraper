# _D3DDDIARG_UNLOCKASYNC structure

## Description

The D3DDDIARG_UNLOCKASYNC structure describes a resource or a surface within the resource to unlock.

## Members

### `hResource` [in]

A handle to the resource to be unlocked.

### `SubResourceIndex` [in]

The zero-based index into the resource that **hResource** specifies. This index indicates the subresource or surface to be unlocked.

### `Flags` [in]

A [D3DDDI_UNLOCKASYNCFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_unlockasyncflags) structure that indicates, in bit-field flags, how to unlock the resource.

## See also

[UnlockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockasync)