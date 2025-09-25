# IGetClusterObjectInfo::GetObjectType

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Returns the type of a
[cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects).

## Parameters

### `lObjIndex` [in]

A number representing the zero-based index of the target object. This parameter is restricted to the number
that can be retrieved by calling
[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount).

## Return value

If [GetObjectType](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterobjectinfo-getobjecttype) is
successful, it returns one of the following values enumerated by the
**CLUADMEX_OBJECT_TYPE** enumeration representing the object types:

If **GetObjectType** is not
successful, it returns –1. For more information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**CLUADMEX_OT_NONE** is returned when
[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) does not recognize
the object type.

## See also

[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount)

[IGetClusterObjectInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterobjectinfo)