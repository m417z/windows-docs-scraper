# IMFASFStreamConfig::GetMediaType

## Description

Retrieves the media type of the stream.

## Parameters

### `ppIMediaType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type object associated with the stream. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To reduce unnecessary copying, the method returns a pointer to the media type that is stored internally by the object. Do not modify the returned media type, as the results are not defined.

## See also

[IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig)

[IMFASFStreamConfig::SetMediaType](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamconfig-setmediatype)

[IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype)