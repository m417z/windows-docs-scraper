# ICreateTypeInfo::SetHelpContext

## Description

Sets the Help context ID of the type information.

## Parameters

### `dwHelpContext` [in]

A handle to the Help context.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_ACCESSDENIED** | Cannot write to the destination. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)