# IBackgroundCopyQMgr::CreateGroup

## Description

[**IBackgroundCopyQMgr** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **CreateGroup** method to create a new group and add it to the download queue.

## Parameters

### `guidGroupID` [in]

GUID that uniquely identifies the group in the download queue.

### `ppGroup` [out]

Pointer to an [IBackgroundCopyGroup](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopygroup) interface pointer. Use this interface to manage the group. For example, add a job to the group and set the properties of the group.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully created the group. |
| **E_INVALIDARG** | A group already exists with that GUID. |

## See also

[IBackgroundCopyQMgr](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyqmgr)