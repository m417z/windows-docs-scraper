# IDirectDrawSurface7::GetPrivateData

## Description

Copies the private data that is associated with this surface to a provided buffer.

## Parameters

### `unnamedParam1` [in]

Reference to (C++) or address of (C) the globally unique identifier that identifies the private data to be retrieved.

### `unnamedParam2` [out]

A pointer to a previously allocated buffer that receives the requested private data if the call succeeds. The application that calls this method must allocate and release this buffer.

### `unnamedParam3` [in, out]

A pointer to a variable that contains the size value of the buffer at *lpBuffer*, in bytes. If this value is less than the actual size of the private data (such as 0), **GetPrivateData** sets the variable to the required buffer size, and then returns DDERR_MOREDATA.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_EXPIRED
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_MOREDATA
* DDERR_NOTFOUND
* DDERR_OUTOFMEMORY

## Remarks

If the data returned is a pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown), or one of its derivative classes, which was previously set by **SetPrivateData** with a `DDSPD_IUNKNOWNPOINTER` flag, that interface will have its reference count incremented before the private data is returned.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)