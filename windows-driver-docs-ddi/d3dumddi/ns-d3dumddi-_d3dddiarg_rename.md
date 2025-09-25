# _D3DDDIARG_RENAME structure

## Description

The D3DDDIARG_RENAME structure describes a resource or a surface within the resource to rename with a new allocation.

## Members

### `hResource` [in]

A handle to the resource to be renamed.

### `SubResourceIndex` [in]

The zero-based index into the resource that **hResource** specifies. This index indicates the subresource or surface to be renamed.

### `hCookie` [in]

A handle that represents the renamed surface instance that the [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync) function previously returned.

### `GpuVirtualAddress`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

## See also

[LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync)

[Rename](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rename)