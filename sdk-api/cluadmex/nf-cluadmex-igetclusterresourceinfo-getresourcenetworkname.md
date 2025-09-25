# IGetClusterResourceInfo::GetResourceNetworkName

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Returns the name of the [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) managed by the
[Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource on which a
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) depends.

## Parameters

### `lObjIndex` [in]

A number representing the zero-based index of the target resource. The target resource may or may not depend
on a Network Name resource. *lObjIndex* is restricted to the number that can be
retrieved by calling
[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount).

### `lpszNetName` [out]

Pointer to a null-terminated Unicode string containing the name of the network upon which the resource
indexed by *lObjIndex* depends. Although declared as a
**BSTR**, this parameter is implemented as an **LPWSTR**.

### `pcchNetName` [in, out]

Pointer to the maximum count in characters of the buffer pointed to by *lpszNetName*.
On input, this value should be large enough to contain **MAX_COMPUTERNAME_LENGTH** + 1
characters. On output, *pcchNetName* points to the actual number of characters copied
to the content of *lpszNetName*.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE**<br><br>1 | The resource indexed by *lObjIndex* has a [dependency](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) on a [Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource, and the name of the network was successfully returned. |
| **FALSE**<br><br>0 | The resource indexed by *lObjIndex* does not have a dependency on a Network Name resource. |

## Remarks

The
**GetResourceNetworkName**
method is necessary to allow
[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) extension property
pages to determine whether a resource has an existing or a pending dependency on a Network Name resource.

The name of the network is stored in the Network Name resource's Name private property. The Network Name
resource's Name common property is the name of the resource, not the network.

**MAX_COMPUTERNAME_LENGTH** is a constant defined as 15 in the Windows header file
WinBase.h.

## See also

[IGetClusterDataInfo::GetObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getobjectcount)

[IGetClusterResourceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterresourceinfo)