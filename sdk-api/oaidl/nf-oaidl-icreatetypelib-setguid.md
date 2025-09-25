# ICreateTypeLib::SetGuid

## Description

Sets the universal unique identifier (UUID) associated with the type library (Also known as the globally unique identifier (GUID)).

## Parameters

### `guid` [in]

The globally unique identifier to be assigned to the library.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |

## See also

[ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib)

[Type Libraries and the Object Description Language](https://learn.microsoft.com/previous-versions/windows/desktop/automat/type-libraries-and-the-object-description-language)