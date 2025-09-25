# ITypeInfo::GetContainingTypeLib

## Description

Retrieves the containing type library and the index of the type description within that type library.

## Parameters

### `ppTLib` [out]

The containing type library.

### `pIndex` [out]

The index of the type description within the containing type library.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_NOINTERFACE** | OLE could not find an implementation of one or more required interfaces. |

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)