# ICreateTypeLib::SetHelpContext

## Description

Sets the Help context ID for retrieving general Help information for the type library.

## Parameters

### `dwHelpContext` [in]

The Help context ID.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |

## Remarks

Calling **SetHelpContext** with a Help context of zero is equivalent to not calling it at all, because zero indicates a null Help context.

## See also

[ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib)