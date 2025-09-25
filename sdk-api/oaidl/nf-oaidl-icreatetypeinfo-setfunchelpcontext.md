# ICreateTypeInfo::SetFuncHelpContext

## Description

Sets the Help context ID for the function with the specified index.

## Parameters

### `index` [in]

The index of the function.

### `dwHelpContext` [in]

The Help context ID for the Help topic.

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

**SetFuncHelpContext** only needs to be set once for each property, because all property accessor functions are identified by one name.

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)