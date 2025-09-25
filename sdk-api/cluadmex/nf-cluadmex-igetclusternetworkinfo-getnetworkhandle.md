# IGetClusterNetworkInfo::GetNetworkHandle

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Retrieves a handle to a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks).

## Parameters

### `lObjIndex` [in]

A number representing the zero-based index of the target network. *lObjIndex* is
restricted to the number that can be retrieved by calling
[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount).

## Return value

If **GetNetworkHandle** is
successful, it returns a handle for the network represented by *lObjIndex*.

If **GetNetworkHandle** is not
successful, it returns **NULL**. For more information about the error, call the function
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Do not close the handle obtained through this method.

## See also

[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount)

[IGetClusterNetworkInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternetworkinfo)