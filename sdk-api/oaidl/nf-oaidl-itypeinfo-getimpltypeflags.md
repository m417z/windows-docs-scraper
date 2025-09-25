# ITypeInfo::GetImplTypeFlags

## Description

Retrieves the IMPLTYPEFLAGS enumeration for one implemented interface or base interface in a type description.

## Parameters

### `index` [in]

The index of the implemented interface or base interface for which to get the flags.

### `pImplTypeFlags` [out]

The IMPLTYPEFLAGS enumeration value.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The flags are associated with the act of inheritance, and not with the inherited interface.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)