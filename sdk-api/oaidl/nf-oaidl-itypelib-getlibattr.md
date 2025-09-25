# ITypeLib::GetLibAttr

## Description

Retrieves the structure that contains the library's attributes.

## Parameters

### `ppTLibAttr` [out]

 The library's attributes.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

Use [ITypeLib::ReleaseTLibAttr](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypelib-releasetlibattr) to free the memory occupied by the TLIBATTR structure.

## See also

[ITypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib)