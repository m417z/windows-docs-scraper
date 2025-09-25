# IGetClusterResourceInfo::GetResourceTypeName

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Returns the type of a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources).

## Parameters

### `lObjIndex` [in]

A number representing the zero-based index of the target resource. *lObjIndex* is
restricted to the number that can be retrieved by calling
[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount).

### `lpszResTypeName` [out]

Pointer to the type of the resource associated with *lObjIndex*. The
*lpResTypeName* parameter can be **NULL**, indicating that the
caller is requesting only the length of the
[resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types). Although declared as a
**BSTR**, this parameter is implemented as an **LPWSTR**.

### `pcchResTypeName` [in, out]

On input, pointer to the count of characters in the buffer pointed to by the
*lpResTypeName* parameter. The *pcchResTypeName* parameter
cannot be **NULL**. On output, pointer to the count of characters in the resource type
name stored in the content of *lpResTypeName*, including the
**NULL**-terminating character.

## Return value

If **GetResourceTypeName**
is not successful, it can return other **HRESULT** values.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057 | One or more of the parameters are invalid. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)**<br><br>0x800700ea | The buffer pointed to by *lpResTypeName* is too small to hold the requested resource type. [GetResourceTypeName](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterresourceinfo-getresourcetypename) returns the required number of characters in the content of *pcchResTypeName*. |

## See also

[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount)

[IGetClusterResourceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterresourceinfo)