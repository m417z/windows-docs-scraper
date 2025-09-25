# IBackgroundCopyGroup::CreateJob

## Description

[**IBackgroundCopyGroup** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **CreateJob** method to add a new job to the group. A group can contain only one job.

## Parameters

### `guidJobID` [in]

Uniquely identifies the job in the group and queue.

### `ppJob` [out]

Pointer to an [IBackgroundCopyJob1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyjob1) interface pointer. Use the interface to add files and check the state of the job.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The job was successfully created. |
| **QM_E_INVALID_STATE** | The job is already running. |
| **E_NOTIMPL** | Only one job allowed per group. |

## See also

[IBackgroundCopyGroup](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopygroup)