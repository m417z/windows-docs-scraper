# ICreateTypeLib::SetLibFlags

## Description

Sets library flags.

## Parameters

### `uLibFlags` [in]

The flags to set.

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

Valid *uLibFlags* values are listed in [LIBFLAGS](https://learn.microsoft.com/windows/desktop/api/oaidl/ne-oaidl-libflags).

## See also

[ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib)