# IOleUIObjInfoW::GetObjectInfo

## Description

Gets the size, type, name, and location information for an object.

## Parameters

### `dwObject` [in]

Unique identifier for the object.

### `lpdwObjSize` [out]

Pointer to the object's size, in bytes, on disk. This may be an approximate value.

### `lplpszLabel` [out, optional]

Address of a pointer variable that receives a pointer to the object's label string. This parameter may be **NULL** to indicate that the implementation should not return the label string.

### `lplpszType` [out, optional]

Address of a pointer variable that receives a pointer to the object's long type string. This parameter may be **NULL** to indicate that the implementation should not return the long type string.

### `lplpszShortType` [out, optional]

Address of a pointer variable that receives a pointer to the object's short type string. This parameter may be **NULL** to indicate that the implementation should not return the short type string.

### `lplpszLocation` [out, optional]

Address of a pointer variable that receives a pointer to the object's source location string. This parameter may be **NULL** to indicate that the implementation should not return the location string.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **E_INVALIDARG** | The specified identifier is invalid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

The strings and the object's size are displayed in the object properties **General** page.

### Notes to Implementers

Your implementation of **GetObjectInfo** should place each of the object's attributes in the out parameters provided. Set *lpdwObjSize* to (DWORD)-1 when the size of the object is unknown. Allocate all strings (the rest of the params) with the OLE task allocator obtained via [CoGetMalloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmalloc), as is standard for all OLE interfaces with [out] string parameters, or you can simply use [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc).

## See also

[CoGetMalloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmalloc)

[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc)

[IOleUIObjInfo](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuiobjinfoa)