# IMFASFMutualExclusion::GetRecordCount

## Description

Retrieves the number of records in the Advanced Systems Format mutual exclusion object.

## Parameters

### `pdwRecordCount` [out]

Receives the count of records.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Each record includes one or more streams. Every stream in a record is mutually exclusive of streams in every other record.

Use this method in conjunction with [IMFASFMutualExclusion::GetStreamsForRecord](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-getstreamsforrecord) to retrieve the streams that are included in each record.

## See also

[IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion)

[IMFASFMutualExclusion::AddRecord](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-addrecord)

[IMFASFMutualExclusion::GetStreamsForRecord](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-getstreamsforrecord)

[IMFASFMutualExclusion::RemoveRecord](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-removerecord)

[Using Mutual Exclusion for ASF Streams](https://learn.microsoft.com/windows/desktop/medfound/using-mutual-exclusion-for-asf-streams)