# IMFASFSplitter::GetLastSendTime

## Description

Retrieves the send time of the last sample received.

## Parameters

### `pdwLastSendTime` [out]

Receives the send time of the last sample received.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pdwLastSendTime* is **NULL**. |

## See also

[IMFASFSplitter](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfsplitter)

[IMFASFSplitter::SetFlags](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-setflags)