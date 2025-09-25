# IMFASFMutualExclusion::GetStreamsForRecord

## Description

Retrieves the stream numbers contained in a record in the Advanced Systems Format mutual exclusion object.

## Parameters

### `dwRecordNumber` [in]

The number of the record for which to retrieve the stream numbers.

### `pwStreamNumArray` [out]

An array that receives the stream numbers. Set to **NULL** to get the number of elements required, which is indicated by the value of *pcStreams* on return. If this parameter is not **NULL**, the method will copy as many stream numbers to the array as there are elements indicated by the value of *pcStreams*.

### `pcStreams` [in, out]

On input, the number of elements in the array referenced by *pwStreamNumArray*. On output, the method sets this value to the count of stream numbers in the record. You can call **GetStreamsForRecord** with *pwStreamNumArray* set to **NULL** to retrieve the number of elements required to hold all of the stream numbers.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion)

[Using Mutual Exclusion for ASF Streams](https://learn.microsoft.com/windows/desktop/medfound/using-mutual-exclusion-for-asf-streams)