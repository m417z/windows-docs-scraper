# IMFASFProfile::CreateStream

## Description

Creates an Advanced Systems Format (ASF) stream configuration object.

## Parameters

### `pIMediaType` [in]

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of a configured media type.

### `ppIStream` [out]

Receives a pointer to the [IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig) interface of the new ASF stream configuration object. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *ppIStream* is **NULL**. |
| **E_OUTOFMEMORY** | stream configuration object could not be created due to insufficient memory. |

## Remarks

The ASF stream configuration object created by this method is not included in the profile. To include the stream, you must first configure the stream configuration and then call [IMFASFProfile::SetStream](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-setstream).

## See also

[ASF Profile](https://learn.microsoft.com/windows/desktop/medfound/asf-profile)

[IMFASFProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfprofile)

[IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig)

[IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype)