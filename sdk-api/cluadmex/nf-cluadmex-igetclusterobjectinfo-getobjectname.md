# IGetClusterObjectInfo::GetObjectName

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Returns the name of a [cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects).

## Parameters

### `lObjIndex` [in]

A number representing the zero-based index of the target object. *lObjIndex* is
restricted to the number that can be retrieved by calling
[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount).

### `lpszName` [out]

Pointer to a null-terminated Unicode string containing the name of the object associated with
*lObjIndex*. The *lpszName* parameter can be
**NULL**, indicating that the caller is requesting only the name length. Although
declared as a **BSTR**, this parameter is implemented as an
**LPWSTR**.

### `pcchName` [in, out]

On input, pointer to the count of characters in the buffer pointed to by the
*lpszName* parameter. The *pcchName* parameter cannot be
**NULL**. On output, pointer to the count of characters in the name stored in the content
of *lpszName*, including the **NULL**-terminating character.

## Return value

If **GetObjectName** is not
successful, it can return other **HRESULT** values.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057 | One or more of the parameters are invalid. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)**<br><br>0x800700ea | The buffer pointed to by *lpszName* is too small to hold the requested name. [GetObjectName](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterobjectinfo-getobjectname) returns the required number of characters in the content of *pcchName*. |

## Remarks

If the *lpszName* parameter is specified as **NULL**, the
**GetObjectName** method returns
**NOERROR**.

## See also

[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount)

[IGetClusterObjectInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterobjectinfo)