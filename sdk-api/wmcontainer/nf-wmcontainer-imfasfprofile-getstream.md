# IMFASFProfile::GetStream

## Description

Retrieves a stream from the profile by stream index, and/or retrieves the stream number for a stream index.

## Parameters

### `dwStreamIndex` [in]

The index of the stream to retrieve. Stream indexes are sequential and zero-based. You can get the number of streams that are in the profile by calling the [IMFASFProfile::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-getstreamcount) method.

### `pwStreamNumber` [out]

Receives the stream number of the requested stream. Stream numbers are one-based and are not necessarily sequential. This parameter can be set to **NULL** if the stream number is not required.

### `ppIStream` [out]

Receives a pointer to the [IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig) interface of the ASF stream configuration object. The caller must release the interface. This parameter can be **NULL** if you want to retrieve the stream number without accessing the stream configuration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method does not create a copy of the stream configuration object. The pointer that is retrieved points to the object within the profile object. You must not make any changes to the stream configuration object using this pointer, because doing so can affect the profile object in unexpected ways.

To change the configuration of the stream configuration object in the profile, you must first clone the stream configuration object by calling [IMFASFStreamConfig::Clone](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamconfig-clone). Make whatever changes are required to the clone of the object and then add the updated object by calling the [IMFASFProfile::SetStream](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-setstream) method.

## See also

[ASF Profile](https://learn.microsoft.com/windows/desktop/medfound/asf-profile)

[IMFASFProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfprofile)

[IMFASFProfile::GetStreamByNumber](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-getstreambynumber)

[IMFASFProfile::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-getstreamcount)

[IMFASFProfile::RemoveStream](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-removestream)

[IMFASFProfile::SetStream](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-setstream)

[IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig)