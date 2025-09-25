# ICreateTypeLib::SetDocString

## Description

Sets the documentation string associated with the library.

## Parameters

### `szDoc` [in]

A brief description of the type library.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The documentation string is a brief description of the library intended for use by type information browsing tools.

## See also

[ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib)