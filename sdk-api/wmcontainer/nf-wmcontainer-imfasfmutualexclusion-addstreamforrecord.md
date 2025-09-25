# IMFASFMutualExclusion::AddStreamForRecord

## Description

Adds a stream number to a record in the Advanced Systems Format mutual exclusion object.

## Parameters

### `dwRecordNumber` [in]

The record number to which the stream is added. A record number is set by the [IMFASFMutualExclusion::AddRecord](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-addrecord) method.

### `wStreamNumber` [in]

The stream number to add to the record.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The specified stream number is already associated with the record. |

## Remarks

Each record includes one or more streams. Every stream in a record is mutually exclusive of all streams in every other record.

## See also

[IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion)

[IMFASFMutualExclusion::GetStreamsForRecord](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-getstreamsforrecord)

[IMFASFMutualExclusion::RemoveStreamFromRecord](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-removestreamfromrecord)

[Using Mutual Exclusion for ASF Streams](https://learn.microsoft.com/windows/desktop/medfound/using-mutual-exclusion-for-asf-streams)