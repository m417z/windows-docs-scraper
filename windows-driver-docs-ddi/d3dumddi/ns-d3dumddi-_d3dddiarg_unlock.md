# _D3DDDIARG_UNLOCK structure

## Description

The D3DDDIARG_UNLOCK structure describes a resource or a surface within the resource to unlock.

## Members

### `hResource` [in]

A handle to the resource to be unlocked.

### `SubResourceIndex` [in]

The zero-based index into the resource, which is specified by the handle in the **hResource** member. This index indicates the subresource or surface to be unlocked.

### `Flags` [in]

A [D3DDDI_UNLOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_unlockflags) structure that indicates, in bit-field flags, how to unlock the resource.

## See also

[D3DDDI_UNLOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_unlockflags)

[Unlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlock)