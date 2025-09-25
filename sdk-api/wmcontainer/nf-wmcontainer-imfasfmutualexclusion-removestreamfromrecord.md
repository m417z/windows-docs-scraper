# IMFASFMutualExclusion::RemoveStreamFromRecord

## Description

Removes a stream number from a record in the Advanced Systems Format mutual exclusion object.

## Parameters

### `dwRecordNumber` [in]

The record number from which to remove the stream number.

### `wStreamNumber` [in]

The stream number to remove from the record.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The stream number is not listed for the specified record. |

## See also

[IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion)

[Using Mutual Exclusion for ASF Streams](https://learn.microsoft.com/windows/desktop/medfound/using-mutual-exclusion-for-asf-streams)