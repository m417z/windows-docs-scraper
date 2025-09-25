# IEntity::Name

## Description

Retrieves the name of this entity.

## Parameters

### `ppszName` [out, retval]

Type: **LPWSTR***

Receives a pointer to the name of this entity as a Unicode string. The calling application must free the returned string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Each name must be unique.