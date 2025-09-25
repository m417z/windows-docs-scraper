# IMSVidStreamBufferSink::get_SBESink

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SBESink** method retrieves a pointer to the [Stream Buffer Sink](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-sink-filter) filter.

## Parameters

### `sbeConfig` [out]

Receives a pointer to the filter's **IUnknown** interface.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The caller must release the **IUnknown** interface.

## See also

[IMSVidStreamBufferSink Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidstreambuffersink)