# _D3DDDI_LOCKFLAGS structure

## Description

The D3DDDI_LOCKFLAGS structure identifies how to lock a resource.

## Members

### `ReadOnly`

A UINT value that specifies whether the locked resource can only be read from. Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `WriteOnly`

A UINT value that specifies whether the locked resource can only be written to. Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `NoOverwrite`

A UINT value that specifies whether the locked resource can have data appended to it but the existing data in the resource cannot be modified. This member is used only with Direct3D vertex buffer locks.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `Discard`

A UINT value that specifies whether the entire locked resource is modified. Therefore, because the existing contents can be discarded, they require no preliminary processing.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `RangeValid`

A UINT value that specifies whether the locked resource is linear.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `AreaValid`

A UINT value that specifies whether the locked resource is a surface.

Setting this member is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

### `BoxValid`

A UINT value that specifies whether the locked resource is a volume.

Setting this member is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

### `NotifyOnly`

A UINT value that specifies whether the lock call is for notification only.

Setting this member is equivalent to setting the eighth bit of the 32-bit **Value** member (0x00000080).

### `MightDrawFromLocked`

A UINT value that specifies whether the driver is possibly requested to draw from a vertex buffer even if the vertex buffer is locked by the Direct3D runtime. **MightDrawFromLocked** does not guarantee that the driver will receive calls to its [DrawIndexedPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive), [DrawIndexedPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive2), [DrawPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive), and [DrawPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive2) functions following the call to **Lock**. **MightDrawFromLocked** is set only on vertex buffers that were created with the **MightDrawFromLocked** bit-field flag set in the **Flags** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure during create time.

Setting this member is equivalent to setting the ninth bit of the 32-bit **Value** member (0x00000100).

### `DoNotWait`

A UINT value that specifies whether the user-mode display driver should wait for the resource to become idle. Setting **DoNotWait** indicates that the user-mode display driver should not wait for the resource to become idle.

Setting this member is equivalent to setting the tenth bit of the 32-bit **Value** member (0x00000200).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 22 bits (0xFFFFFC00) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDI_LOCKFLAGS that can hold one 32-bit value that identifies how to lock a resource.

## See also

[D3DDDIARG_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lock)