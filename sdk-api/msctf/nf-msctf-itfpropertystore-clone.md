# ITfPropertyStore::Clone

## Description

Creates an exact copy of the property store object.

## Parameters

### `pPropStore` [out]

Pointer to an [ITfPropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpropertystore) interface pointer that receives the new property store object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## Remarks

This method creates a new property store object and initializes the new object so that it will operate as an exact copy of the original property store object. The new object must be completely independent of the original object.

## See also

[ITfPropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpropertystore)