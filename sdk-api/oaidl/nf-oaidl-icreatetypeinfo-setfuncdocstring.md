# ICreateTypeInfo::SetFuncDocString

## Description

Sets the documentation string for the function with the specified index.

## Parameters

### `index` [in]

The index of the function.

### `szDocString` [in]

The documentation string.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_ACCESSDENIED** | Cannot write to the destination. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_ELEMENTNOTFOUND** | The element cannot be found. |

## Remarks

The documentation string is a brief description of the function intended for use by tools such as type browsers. **SetFuncDocString** only needs to be used once for each property, because all property accessor functions are identified by one name.

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)