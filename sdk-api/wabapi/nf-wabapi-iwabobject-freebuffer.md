# IWABObject::FreeBuffer

## Description

Frees memory allocated with
[IWABObject::AllocateBuffer](https://learn.microsoft.com/windows/desktop/api/wabapi/nf-wabapi-iwabobject-allocatebuffer) or any of the other
Windows Address Book (WAB) methods.

## Parameters

### `lpBuffer`

Type: **LPVOID**

Pointer to the buffer to be freed.

## Return value

Type: **HRESULT**

Returns S_OK if the call succeeded
and freed the memory requested.