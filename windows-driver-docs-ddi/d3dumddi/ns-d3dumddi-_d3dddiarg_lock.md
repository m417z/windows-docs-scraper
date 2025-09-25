# _D3DDDIARG_LOCK structure

## Description

The D3DDDIARG_LOCK structure describes a resource or a surface within the resource to lock.

## Members

### `hResource` [in]

A handle to the resource to be locked.

### `SubResourceIndex` [in]

The zero-based index into the resource, which is specified by the handle that is specified by **hResource**. This index indicates the subresource or surface to be locked.

### `Range` [in]

A D3DDDIRANGE structure that describes the subrange of the linear resource to lock.

### `Area` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that describes the subrectangle of the surface to lock.

### `Box` [in]

A D3DDDIBOX structure that describes the subvolume of the volume to lock.

### `pSurfData` [out]

A pointer to the memory region for the resource that was locked. The user-mode display driver's [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) function returns this pointer to the Microsoft Direct3D runtime.

### `Pitch` [out]

The pitch, in bytes, of the surface that was locked. The user-mode display driver's [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) function returns this pitch value to the Direct3D runtime.

### `SlicePitch` [out]

The slice pitch, in bytes, of the surface that was locked. The user-mode display driver's [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) function returns this slice pitch value to the Direct3D runtime.

### `Flags` [in]

A [D3DDDI_LOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_lockflags) structure that indicates, in bit-field flags, how to lock the resource. Note that some flags are mutually exclusive with other flags. For more information, see the following Remarks section.

## Remarks

The members of the structure that is specified by the **Flags** member must adhere to the following rules:

* The **ReadOnly** and **WriteOnly** bit-field flags must not be set simultaneously.
* The **NoOverwrite** bit-field flag must not be simultaneously set with the **Discard** bit-field flag.
* Only one of the **RangeValid**, **AreaValid**, and **BoxValid** bit-field flags must be set at any time.
* The **ReadOnly** bit-field flag must not be simultaneously set with the **Discard** bit-field flag.

## See also

[D3DDDI_LOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_lockflags)

[Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock)