# IMSVidStreamBufferRecordingControl::get_RecordingAttribute

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_RecordingAttribute** method retrieves the stream buffer [Recording](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/recording-object) object that is controlled by this interface.

## Parameters

### `pRecordingAttribute` [out]

Address of a variable that receives a pointer to the [Recording](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/recording-object) object's **IUnknown** interface.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The caller must release the returned **IUnknown** pointer.

## See also

[IMSVidStreamBufferRecordingControl Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferrecordingcontrol)