# _D3DDDIARG_LOCKASYNC structure

## Description

The D3DDDIARG_LOCKASYNC structure describes a resource or a surface within the resource to lock.

## Members

### `hResource` [in]

A handle to the resource to be locked.

### `SubResourceIndex` [in]

The zero-based index into the resource that **hResource** specifies. This index indicates the subresource or surface to be locked.

### `Flags` [in]

A [D3DDDI_LOCKASYNCFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_lockasyncflags) structure that indicates, in bit-field flags, how to lock the resource.

**Note** Some flags are mutually exclusive with other flags. For more information, see the following Remarks section.

### `Range` [in]

A D3DDDIRANGE structure that describes the subrange of the linear resource to lock, if the **RangeValid** bit-field flag is set in the D3DDDI_LOCKASYNCFLAGS structure that **Flags** specifies.

### `Area` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that describes the subrectangle of the surface to lock, if the **AreaValid** bit-field flag is set in the D3DDDI_LOCKASYNCFLAGS structure that **Flags** specifies.

### `Box` [in]

A D3DDDIBOX structure that describes the subvolume of the volume to lock, if the **BoxValid** bit-field flag is set in the D3DDDI_LOCKASYNCFLAGS structure that **Flags** specifies.

### `hCookie` [out]

A handle that represents the renamed resource. This handle is valid only if the **Discard** bit-field flag is set in the D3DDDI_LOCKASYNCFLAGS structure that **Flags** specifies.

### `pSurfData` [out]

A pointer to the memory region for the resource that was locked. The user-mode display driver's [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync) function returns this pointer to the Microsoft Direct3D runtime.

### `Pitch` [out]

The pitch, in bytes, of the surface that was locked. The user-mode display driver's [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync) function returns this pitch value to the Direct3D runtime.

### `SlicePitch` [out]

The slice pitch, in bytes, of the surface that was locked. The user-mode display driver's [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync) function returns this slice pitch value to the Direct3D runtime.

### `GpuVirtualAddress`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

## Remarks

The members of the [D3DDDI_LOCKASYNCFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_lockasyncflags) structure that the **Flags** member specifies must adhere to the following rules:

* The **NoOverwrite** bit-field flag must not be simultaneously set with the **Discard** bit-field flag.
* Only one of the **RangeValid**, **AreaValid**, and **BoxValid** bit-field flags must be set at any time.

## See also

[D3DDDI_LOCKASYNCFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_lockasyncflags)

[LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)