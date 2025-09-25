# IGetClusterGroupInfo::GetGroupHandle

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Returns a handle to a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups).

## Parameters

### `lObjIndex` [in]

A number representing the zero-based index of the target group. *lObjIndex* is
restricted to the number that can be retrieved by calling
[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount).

## Return value

If **GetGroupHandle** is
successful, it returns a handle for the group represented by *lObjIndex*.

If **GetGroupHandle** is not
successful, it returns **NULL**. For more information about the error, call the function
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Do not close the handle obtained through this method.

## See also

[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount)

[IGetClusterGroupInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclustergroupinfo)