## Description

Retrieves the index of the first part that has the specified kind.

## Parameters

### `kind`

The kind to search for.

### `pResult`

A pointer to the variable in which to receive the index of the matching part.

## Return value

**S_OK** on success, or **E_NOT_VALID_STATE** if a container has not been loaded by using [Load](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxccontainerreflection-load), or **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** if there's no part with the specified kind, or another standard **HRESULT** error code.

## Remarks

## See also