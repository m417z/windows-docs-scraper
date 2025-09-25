# IRecordInfo::GetName

## Description

Gets the name of the record type. This is useful if you want to print out the type of the record, because each UDT has its own [IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo).

## Parameters

### `pbstrName` [out]

The name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUT_OFMEMORY** | Out of memory. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |

## Remarks

The caller must free the BSTR by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)