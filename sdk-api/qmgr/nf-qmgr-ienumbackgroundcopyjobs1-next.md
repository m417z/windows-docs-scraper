# IEnumBackgroundCopyJobs1::Next

## Description

[**IEnumBackgroundCopyJobs1** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **Next** method to retrieve the specified number of items in the enumeration sequence. If there are fewer than the requested number of elements left in the sequence, it retrieves the remaining elements.

## Parameters

### `celt` [in]

Number of elements requested.

### `rgelt` [out]

Array of GUIDs that identify the jobs. To retrieve a job, call the [IBackgroundCopyGroup::GetJob](https://learn.microsoft.com/windows/desktop/api/qmgr/nf-qmgr-ibackgroundcopygroup-getjob) method with the GUID.

### `pceltFetched` [out]

Number of elements in *rgelt*. You can set *pceltFetched* to **NULL** if *celt* is one.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully returned the number of requested elements. |
| **S_FALSE** | Returned less than the number of requested elements. |

## See also

[IEnumBackgroundCopyJobs1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ienumbackgroundcopyjobs1)