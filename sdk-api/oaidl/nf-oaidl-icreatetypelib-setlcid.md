# ICreateTypeLib::SetLcid

## Description

Sets the binary Microsoft national language ID associated with the library.

## Parameters

### `lcid` [in]

The locale ID for the type library.

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

For more information on national language IDs, see [Supporting Multiple National Languages](https://learn.microsoft.com/previous-versions/windows/desktop/automat/supporting-multiple-national-languages) and the National Language Support (NLS) API.

## See also

[ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib)