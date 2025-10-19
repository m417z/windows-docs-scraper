# IBackgroundCopyGroup::GetStatus

## Description

[**IBackgroundCopyGroup** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **GetStatus** method to retrieve the state of the group.

## Parameters

### `pdwStatus` [out]

State of the group. The state can be set to one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **QM_STATUS_GROUP_FOREGROUND** | QMGR is downloading the group in the foreground. |
| **QM_STATUS_GROUP_INCOMPLETE** | QMGR is still downloading the group. |
| **QM_STATUS_GROUP_SUSPENDED** | The group is suspended. |
| **QM_STATUS_GROUP_ERROR** | An error occurred while processing the group. |

### `pdwJobIndex`

Current job in progress. The index is always 0 (groups can only contain one job).

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully retrieved the state of the group. |

## See also

[IBackgroundCopyGroup](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopygroup)