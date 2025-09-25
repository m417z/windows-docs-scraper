# IMFASFStreamPrioritization::RemoveStream

## Description

**Note** This interface is not implemented in this version of Media Foundation.

Removes a stream from the stream priority list.

## Parameters

### `dwStreamIndex` [in]

Index of the entry in the stream priority list to remove. Values range from zero, to one less than the stream count retrieved by calling [IMFASFStreamPrioritization::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamprioritization-getstreamcount).

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When a stream is removed from the stream priority list, the index values of all streams that follow it in the list are decremented.

## See also

[IMFASFStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamprioritization)