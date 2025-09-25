# IMSVidStreamBufferSource2::get_WSTCounter

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_WSTCounter** method enables the caller to get performance statistics from the Stream Buffer Source for the World Standard Teletext (WST) stream.

## Parameters

### `ppUnk` [out]

Receives a pointer to the **IUnknown** interface. Query this pointer for the [IStreamBufferDataCounters](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferdatacounters) interface. The caller must release the **IUnknown** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMSVidStreamBufferSource2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambuffersource2)