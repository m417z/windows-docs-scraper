# IBackgroundCopyQMgr::EnumGroups

## Description

[**IBackgroundCopyQMgr** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **EnumGroups** method to retrieve a list of groups that the current user owns. If the current user has Administrator privileges, the method returns all groups in the queue.

## Parameters

### `dwFlags` [in]

Must be 0.

### `ppEnumGroups` [out]

Pointer to an [IEnumBackgroundCopyGroups](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ienumbackgroundcopygroups) interface pointer. Use this interface to retrieve a group from the list.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved a list of the groups in the download queue. |
| **E_NOTIMPL** | The *dwFlags* parameter must be 0. |

## See also

[IBackgroundCopyQMgr](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyqmgr)