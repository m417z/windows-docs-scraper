# IWABObject::AllocateBuffer

## Description

Allocates memory for buffers that are passed to
Windows Address Book (WAB) methods. The buffer must be freed with
[IWABObject::FreeBuffer](https://learn.microsoft.com/windows/desktop/api/wabapi/nf-wabapi-iwabobject-freebuffer), and may be reallocated with
[IWABObject::AllocateMore](https://learn.microsoft.com/windows/desktop/api/wabapi/nf-wabapi-iwabobject-allocatemore).

## Parameters

### `cbSize`

Type: **ULONG**

Value of type **ULONG** that specifies the size
in bytes of the buffer to be allocated.

### `lppBuffer`

Type: **LPVOID***

Address of a pointer to the returned buffer.

## Return value

Type: **HRESULT**

Returns S_OK if the requested buffer was successfully
allocated.