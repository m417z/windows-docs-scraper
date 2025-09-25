## Description

Retrieves the content of the specified part.

## Parameters

### `idx`

The index of the part to retrieve.

### `ppResult`

A pointer to the variable in which to receive the result.

## Return value

**S_OK** on success, or **E_NOT_VALID_STATE** if a container has not been loaded by using [Load](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxccontainerreflection-load), or **E_BOUND** if *idx* is out of bounds, or another standard **HRESULT** error code.

## Remarks

## See also