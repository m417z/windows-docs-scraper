# IMFASFStreamPrioritization::GetStream

## Description

**Note** This interface is not implemented in this version of Media Foundation.

Retrieves the stream number of a stream in the stream priority list.

## Parameters

### `dwStreamIndex` [in]

Zero-based index of the entry to retrieve from the stream priority list. To get the number of entries in the priority list, call [IMFASFStreamPrioritization::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamprioritization-getstreamcount).

### `pwStreamNumber` [out]

Receives the stream number of the stream priority entry.

### `pwStreamFlags` [out]

Receives a Boolean value. If **TRUE**, the stream is mandatory.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | **NULL** pointer argument or the *dwStreamIndex* parameter is out of range. |

## See also

[IMFASFStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamprioritization)