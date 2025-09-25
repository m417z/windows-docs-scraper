# ClusterGroupSetEnum function

## Description

Returns the next enumerable object.

## Parameters

### `hGroupSetEnum` [in]

A handle to an open cluster node enumeration
returned by [ClusterNodeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeopenenum)

### `dwIndex` [in]

The index to enumerate, zero for the first call to this function and then
incremented for subsequent calls.

### `lpszName` [out]

Points to a buffer that receives the name of the object,
including the terminating null character.

### `lpcchName` [in, out]

Points to a variable that specifies the size, in characters,
of the buffer pointed to by the *lpszName* parameter. This size
should include the terminating null character. When the function
returns, the variable contains the
number of characters stored in the buffer, not including the terminating null character.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).