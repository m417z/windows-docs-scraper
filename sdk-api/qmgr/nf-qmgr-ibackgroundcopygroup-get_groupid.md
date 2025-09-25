# IBackgroundCopyGroup::get_GroupID

## Description

[**IBackgroundCopyGroup** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **get_GroupID** method to retrieve the group's identifier.

## Parameters

### `pguidGroupID` [out]

GUID that uniquely identifies the group within the download queue.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the GUID that identifies the group. |

## See also

[IBackgroundCopyGroup](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopygroup)