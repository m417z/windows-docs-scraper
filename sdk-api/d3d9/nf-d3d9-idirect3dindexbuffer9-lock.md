# IDirect3DIndexBuffer9::Lock

## Description

Locks a range of index data and obtains a pointer to the index buffer memory.

## Parameters

### `OffsetToLock` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset into the index data to lock, in bytes. Lock the entire index buffer by specifying 0 for both parameters, SizeToLock and OffsetToLock.

### `SizeToLock` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the index data to lock, in bytes. Lock the entire index buffer by specifying 0 for both parameters, SizeToLock and OffsetToLock.

### `ppbData` [out]

Type: **VOID****

VOID* pointer to a memory buffer containing the returned index data.

### `Flags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of zero or more locking flags that describe the type of lock to perform. For this method, the valid flags are:

* D3DLOCK_DISCARD
* D3DLOCK_NO_DIRTY_UPDATE
* D3DLOCK_NOSYSLOCK
* D3DLOCK_READONLY
* D3DLOCK_NOOVERWRITE

For a description of the flags, see [D3DLOCK](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlock).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

As a general rule, do not hold a lock across more than one frame. When working with index buffers, you are allowed to make multiple lock calls. However, you must ensure that the number of lock calls match the number of unlock calls. [IDirect3DDevice9::DrawIndexedPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitive) calls will not succeed with any outstanding lock count on any currently set index buffer.

The D3DLOCK_DISCARD and D3DLOCK_NOOVERWRITE flags are valid only on buffers created with D3DUSAGE_DYNAMIC.

See [Programming Tips (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/programming-tips) for information about using D3DLOCK_DISCARD or D3DLOCK_NOOVERWRITE.

## See also

[IDirect3DIndexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dindexbuffer9)

[IDirect3DIndexBuffer9::Unlock](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dindexbuffer9-unlock)

[Index Buffers (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/index-buffers)