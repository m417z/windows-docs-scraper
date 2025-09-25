# ICreateTypeInfo::DefineFuncAsDllEntry

## Description

Associates a DLL entry point with the function that has the specified index.

## Parameters

### `index` [in]

The index of the function.

### `szDllName` [in]

The name of the DLL that contains the entry point.

### `szProcName` [in]

The name of the entry point or an ordinal (if the high word is zero).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_ELEMENTNOTFOUND** | The element cannot be found. |
| **TYPE_E_WRONGTYPEKIND** | Type mismatch. |

## Remarks

If the high word of *szProcName* is zero, then the low word must contain the ordinal of the entry point; otherwise, *szProcName* points to the zero-terminated name of the entry point.

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)