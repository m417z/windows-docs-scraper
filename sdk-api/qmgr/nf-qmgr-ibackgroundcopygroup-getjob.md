# IBackgroundCopyGroup::GetJob

## Description

[**IBackgroundCopyGroup** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **GetJob** method to retrieve a job from the group.

## Parameters

### `jobID` [in]

Identifies the job to retrieve.

### `ppJob` [out]

Pointer to an [IBackgroundCopyJob1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyjob1) interface pointer. Use the interface to add files and retrieve the state of the job.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the job from the group. |
| **QM_E_ITEM_NOT_FOUND** | Could not find the job in the group. |

## See also

[IBackgroundCopyGroup](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopygroup)