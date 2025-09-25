# _D3DDDI_LOCKASYNCFLAGS structure

## Description

The D3DDDI_LOCKASYNCFLAGS structure identifies how to lock a resource.

## Members

### `NoOverwrite`

A UINT value that specifies whether the locked resource can have data appended to it but the existing data in the resource cannot be modified. This member is used only with Microsoft Direct3D vertex buffer locks.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Discard`

A UINT value that specifies whether the entire locked resource is modified. If this value is set, because the existing contents can be discarded, the contents require no preliminary processing.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `RangeValid`

A UINT value that specifies whether the locked resource is linear.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `AreaValid`

A UINT value that specifies whether the locked resource is a surface.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `BoxValid`

A UINT value that specifies whether the locked resource is a volume.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `NoExistingReferences`

A UINT value that specifies whether the Microsoft Direct3D runtime has any queued references to the resource to be locked. If **NoExistingReferences** is set, the driver determines that no internally queued references to the resource are available. The driver can then set the **NoExistingReferences** bit-field flag of the [D3DDDICB_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock) structure when the driver calls the [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function to perform a lock-discard operation.

Setting this member is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

### `NotifyOnly`

A UINT value that specifies whether the lock call is for notification only. The Direct3D runtime sets **NotifyOnly** to **TRUE** when it locks runtime-allocated system memory surfaces. In this situation, the runtime ignores the pointer that the driver returns in the **pSurfData** member of the [D3DDDIARG_LOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lockasync) structure.

Setting this member is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 25 bits (0xFFFFFF80) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDI_LOCKASYNCFLAGS that can hold one 32-bit value that identifies how to lock a resource.

## See also

[D3DDDIARG_LOCKASYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lockasync)