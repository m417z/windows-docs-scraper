# IMFASFProfile::SetStream

## Description

Adds a stream to the profile or reconfigures an existing stream.

## Parameters

### `pIStream` [in]

Pointer to the [IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig) interface of a configured ASF stream configuration object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the stream number in the ASF stream configuration object is already included in the profile, the information in the new object replaces the old one. If the profile does not contain a stream for the stream number, the ASF stream configuration object is added as a new stream.

## See also

[ASF Profile](https://learn.microsoft.com/windows/desktop/medfound/asf-profile)

[IMFASFProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfprofile)

[IMFASFProfile::GetStream](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-getstream)

[IMFASFProfile::GetStreamByNumber](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-getstreambynumber)

[IMFASFProfile::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-getstreamcount)

[IMFASFProfile::RemoveStream](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-removestream)

[IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig)