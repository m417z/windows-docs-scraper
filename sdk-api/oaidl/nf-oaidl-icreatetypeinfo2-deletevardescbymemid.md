# ICreateTypeInfo2::DeleteVarDescByMemId

## Description

Deletes the specified VARDESC structure.

## Parameters

### `memid` [in]

The member identifier of the VARDESC to be deleted.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_IOERROR** | The function cannot read from the file. |
| **TYPE_E_INVDATAREAD** | The function cannot read from the file. |
| **TYPE_E_UNSUPFORMAT** | The type library has an old format. |
| **TYPE_E_INVALIDSTATE** | The type library cannot be opened. |

## See also

[ICreateTypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo2)