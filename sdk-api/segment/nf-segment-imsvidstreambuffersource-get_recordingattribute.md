# IMSVidStreamBufferSource::get_RecordingAttribute

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_RecordingAttribute** method retrieves the [Stream Buffer Source](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter) filter that this object manages.

## Parameters

### `pRecordingAttribute` [out]

Receives a pointer to the filter's **IUnknown** interface.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The caller must release the returned **IUnknown** interface.

## See also

[IMSVidStreamBufferSource Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidstreambuffersource)