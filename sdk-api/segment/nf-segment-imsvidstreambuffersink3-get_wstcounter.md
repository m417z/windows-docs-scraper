# IMSVidStreamBufferSink3::get_WSTCounter

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **get_WSTCounter** method enables the caller to get performance statistics from the Stream Buffer Sink for the World Standard Teletext (WST) stream.

## Parameters

### `ppUnk` [out]

Receives a pointer to the **IUnknown** interface. Query this pointer for the [IStreamBufferDataCounters](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferdatacounters) interface. The caller must release the **IUnknown** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMSVidStreamBufferSink3 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambuffersink3)