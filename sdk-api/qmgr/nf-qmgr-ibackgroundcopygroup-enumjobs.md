# IBackgroundCopyGroup::EnumJobs

## Description

[**IBackgroundCopyGroup** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **EnumJobs** method to retrieve a list of jobs in the group. The list contains only one job.

## Parameters

### `dwFlags` [in]

Must be 0.

### `ppEnumJobs` [out]

Pointer to an [IEnumBackgroundCopyJobs1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ienumbackgroundcopyjobs1) interface pointer. Use the interface to iterate through the list of jobs.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully enumerated the jobs in the group. |
| **E_NOTIMPL** | The *dwFlags* parameter must be 0. |

## See also

[IBackgroundCopyGroup](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopygroup)