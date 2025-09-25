# IMFASFMutualExclusion::RemoveRecord

## Description

Removes a record from the Advanced Systems Format (ASF) mutual exclusion object.

## Parameters

### `dwRecordNumber` [in]

The index of the record to remove.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When a record is removed, the ASF mutual exclusion object indexes the remaining records so that they are sequential starting with zero. You should enumerate the records to ensure that you have the correct index for each record. If the record removed is the one with the highest index, removing it has no effect on the other indexes.

## See also

[IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion)

[IMFASFMutualExclusion::AddRecord](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-addrecord)

[Using Mutual Exclusion for ASF Streams](https://learn.microsoft.com/windows/desktop/medfound/using-mutual-exclusion-for-asf-streams)