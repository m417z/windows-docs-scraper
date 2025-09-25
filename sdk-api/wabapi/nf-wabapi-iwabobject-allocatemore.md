# IWABObject::AllocateMore

## Description

Allocates a memory buffer that is linked to another buffer
previously allocated with the
[IWABObject::AllocateBuffer](https://learn.microsoft.com/windows/desktop/api/wabapi/nf-wabapi-iwabobject-allocatebuffer) method.

## Parameters

### `cbSize`

Type: **ULONG**

Value of type **ULONG** that specifies
the size in bytes of the buffer to be allocated.

### `lpObject`

Type: **LPVOID**

Pointer to the existing buffer object allocated using
[IWABObject::AllocateBuffer](https://learn.microsoft.com/windows/desktop/api/wabapi/nf-wabapi-iwabobject-allocatebuffer).

### `lppBuffer`

Type: **LPVOID***

Address of a pointer to the returned buffer. This buffer is linked to
*lpObject*.

## Return value

Type: **HRESULT**

Returns S_OK if successful.

## Remarks

It is only possible to release a buffer allocated with
**IWABObject::AllocateMore** by passing the buffer pointer
specified in the *lpObject* parameter to
[IWABObject::FreeBuffer](https://learn.microsoft.com/windows/desktop/api/wabapi/nf-wabapi-iwabobject-freebuffer). The link between the memory
buffers allocated with [IWABObject::AllocateBuffer](https://learn.microsoft.com/windows/desktop/api/wabapi/nf-wabapi-iwabobject-allocatebuffer) and
**IWABObject::AllocateMore** enables
**IWABObject::FreeBuffer** to release both buffers
with a single call.