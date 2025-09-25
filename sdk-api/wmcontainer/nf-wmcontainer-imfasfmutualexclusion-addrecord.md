# IMFASFMutualExclusion::AddRecord

## Description

Adds a record to the mutual exclusion object. A record specifies streams that are mutually exclusive with the streams in all other records.

## Parameters

### `pdwRecordNumber` [out]

Receives the index assigned to the new record. Record indexes are zero-based and sequential.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

A record can include one or more stream numbers. All of the streams in a record are mutually exclusive with all the streams in all other records in the ASF mutual exclusion object.

You can use records to create complex mutual exclusion scenarios by using multiple ASF mutual exclusion objects.

## See also

[IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion)

[IMFASFMutualExclusion::RemoveRecord](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-removerecord)

[Using Mutual Exclusion for ASF Streams](https://learn.microsoft.com/windows/desktop/medfound/using-mutual-exclusion-for-asf-streams)