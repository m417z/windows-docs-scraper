# ITypeLib::GetTypeInfoOfGuid

## Description

Retrieves the type description that corresponds to the specified GUID.

## Parameters

### `guid` [in]

The GUID of the type description.

### `ppTinfo` [out]

The [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **TYPE_E_ELEMENTNOTFOUND** | No type description was found in the library with the specified GUID. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ITypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib)