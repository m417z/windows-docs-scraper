# IMFASFStreamConfig::SetMediaType

## Description

Sets the media type for the Advanced Systems Format (ASF) stream configuration object.

## Parameters

### `pIMediaType` [in]

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of a configured media type object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Some validation of the media type is performed by this method. However, a media type can be successfully set, but cause an error when the stream is added to the profile.

## See also

[IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig)

[IMFASFStreamConfig::GetMediaType](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamconfig-getmediatype)

[IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype)