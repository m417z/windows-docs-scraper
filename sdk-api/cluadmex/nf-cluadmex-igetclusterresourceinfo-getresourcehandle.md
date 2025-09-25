# IGetClusterResourceInfo::GetResourceHandle

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Returns a handle to a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources).

## Parameters

### `lObjIndex` [in]

A number representing the zero-based index of the target resource. *lObjIndex* is
restricted to the number that can be retrieved by calling
[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount).

## Return value

If **GetResourceHandle** is
successful, it returns a handle for the resource represented by *lObjIndex*.

If **GetResourceHandle** is
not successful, it returns **NULL**. For more information about the error, call the
function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount)

[IGetClusterResourceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterresourceinfo)