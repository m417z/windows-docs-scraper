# IMFASFProfile::GetStreamByNumber

## Description

Retrieves an Advanced Systems Format (ASF) stream configuration object for a stream in the profile. This method references the stream by stream number instead of stream index.

## Parameters

### `wStreamNumber` [in]

The stream number for which to obtain the interface pointer.

### `ppIStream` [out]

Receives a pointer to the [IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig) interface of the ASF stream configuration object. The caller must release the interface.

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

[IMFASFProfile::GetStream](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-getstream)

[IMFASFProfile::SetStream](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-setstream)

[IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig)