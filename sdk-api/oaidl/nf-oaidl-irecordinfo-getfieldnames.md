# IRecordInfo::GetFieldNames

## Description

Gets the names of the fields of the record.

## Parameters

### `pcNames` [in, out]

The number of names to return.

### `rgBstrNames` [out]

The name of the array of type BSTR.

If the *rgBstrNames* parameter is NULL, then *pcNames* is returned with the number of field names.

It the *rgBstrNames* parameter is not NULL, then the string names contained in *rgBstrNames* are returned. If the number of names in *pcNames* and *rgBstrNames* are not equal then the lesser number of the two is the number of returned field names. The caller needs to free the BSTRs inside the array returned in *rgBstrNames*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUT_OFMEMORY** | Out of memory. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## Remarks

The caller should allocate memory for the array of BSTRs. If the array is larger than needed, set the unused portion to 0.

On return, the caller will need to free each contained BSTR using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

In case of out of memory, *pcNames* points to error code.

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)