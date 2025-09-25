# IBackgroundCopyQMgr::GetGroup

## Description

[[IBackgroundCopyQMgr](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyqmgr) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **GetGroup** method to retrieve a group from the download queue. The current user can retrieve only groups that they own. If the user has Administrator privileges, the user can retrieve any group from the download queue. Retrieving a group from the queue transfers ownership of the group to the current user.

## Parameters

### `groupID` [in]

GUID that uniquely identifies the group in the download queue.

### `ppGroup` [out]

Pointer to an [IBackgroundCopyGroup](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopygroup) interface pointer. Use this interface to manage the group. For example, add a job to the group and set the properties of the group.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the group. |
| **QM_E_ITEM_NOT_FOUND** | Could not find the group in the download queue. |

## See also

[IBackgroundCopyQMgr](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyqmgr)